#include "mcc_generated_files/mcc.h"
#include <stdio.h>
#include <stdlib.h>
#include "mcc_generated_files/examples/i2c_master_example.h"
#include "font6.h"
#include "font12.h"

#define OLED_addr 0x3C
#define RTC_addr 0x32

#define SECOND 0x00
#define MINUTE 0x10
#define HOUR 0x20
#define DAY 0x30//WEEK
#define DATE 0x40
#define MONTH 0x50
#define YEAR 0x60
#define ALM_D_M 0xB0
#define ALM_D_H 0xC0
#define CTL1 0xE0
#define CTL2 0xF0

uint8_t Page;
uint8_t Column;
uint8_t Low_col;
uint8_t Hi_col;
uint8_t Size;
//int     num;
div_t   res;

typedef struct {
    int quot;  /* 商 */
    int rem;   /* 剰余 */
} div_t;

//??????A?D???Flag
bool AA=false;
bool BB=false;
bool CC=false;
bool DD=false;
bool set_flg;
bool alm_set_flg;
bool alm_active;

uint8_t CLR_cmd[] ={0x00,0x20,0x00,0x21,0x00,0x7F,0x22,0x00,0x07};
uint8_t Posi_cmd[] = {0x00,0x20,0x02,0xB0,0x00,0x00};
uint8_t Font6_data[] = {0x40,0x00,0x00,0x00,0x00,0x00,0x00};
uint8_t Font12_data[] = {0x40,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};


uint16_t result; 
uint16_t Duty;
uint16_t Duty_cmp;
uint16_t Duty2;
uint16_t Duty2_cmp;
uint8_t Duty_add;
int swipe_count;
int wait;
int tadj;
int kind;
int count;
int16_t Message;

char str[256];
char str2[256];

int adj_mode;//設定モード
uint8_t ALM_M;
uint8_t ALM_H;

//時刻設定
//[0]:設定値,[1]:下限,[2]]:上限
uint8_t settei[8][3] = {{0,0,10},{0,0,59},{10,0,59},{21,0,23},{4,0,6},{17,1,31}\
,{10,1,12},{24,20,99}};

//アラーム設定
//[0]  [0]:分_設定値,[1]:下限,[2]]:上限
//[1]  [0]:時_設定値,[1]:下限,[2]]:上限
//[2]  [0]:サーボ選択,[1]:下限,[2]]:上限
//[3]  [0]:回転方向選択,[1]:下限,[2]]:上限
uint8_t alm_settei[4][3] = {{30,0,59},{18,0,23},{0,0,1},{0,0,1}};

char unit[][8]={"DMY1","DMY2","MINUTES","HOUR","WEEK","DAY","MONTH","YEAR"};
char unit2[][4]={"M","H","SRV","DIR"};
char *week[] = {"SUN","MON","TUE","WED","THU","FRI","SAT"};
char alm_unit[][10]={"TOP","BTM","L","R"};
uint8_t REG[8] = {0x00,0x30,0x59,0x18,0x04,0x17,0x10,0x24};
uint8_t REG_addr = 0x00;
char *SRV[] = {"TOP","BTM"};
char *DIR[] = {"L","R"};

void Time_data_write(){
//I2C_Write1ByteRegister(RTC_addr,0x00,0x00);//??????
I2C_Write1ByteRegister(RTC_addr,SECOND,REG[1]);
I2C_Write1ByteRegister(RTC_addr,MINUTE,REG[2]);
I2C_Write1ByteRegister(RTC_addr,HOUR,REG[3]);
I2C_Write1ByteRegister(RTC_addr,DAY,REG[4]);
I2C_Write1ByteRegister(RTC_addr,DATE,REG[5]);
I2C_Write1ByteRegister(RTC_addr,MONTH,REG[6]);
I2C_Write1ByteRegister(RTC_addr,YEAR,REG[7]);
//I2C_Write1ByteRegister(RTC_addr,CTRL,REG[7]);
}

void Time_data_read(){
//I2C_WriteNBytes(RTC_addr,&REG_addr,1);
I2C_WriteNBytes(RTC_addr,0x00,1);
I2C_ReadNBytes(RTC_addr,&REG,7);
}

void ALM_set(uint8_t MM,uint8_t HH){
I2C_Write1ByteRegister(RTC_addr,CTL1,0x20);
I2C_Write1ByteRegister(RTC_addr,ALM_D_M,MM);
I2C_Write1ByteRegister(RTC_addr,ALM_D_H,HH);
I2C_Write1ByteRegister(RTC_addr,CTL2,0x01);
I2C_Write1ByteRegister(RTC_addr,CTL1,0x60);
}

void Alarm_set(){
    
    res=div(alm_settei[0][0],10);
    ALM_M=res.quot*16+res.rem;
    res=div(alm_settei[1][0],10);
    ALM_H=res.quot*16+res.rem;  
    ALM_set(ALM_M,ALM_H);
    alm_active=true;
    
}

void Clock_set(){
    
    //設定値を現在時刻に反映
    for(int i = 0; i < 8; i++) {
        res = div(settei[i][0],10);
        REG[i]=res.quot*16+res.rem;    
    }
    
    Time_data_write();
//        I2C_Write1ByteRegister(RTC_addr,YEAR-16*(7-i),REG[i]);
}

void Pen_swipe(int set_duty){
    PWM11_DutyCycleSet(set_duty);
    PWM11_LoadBufferSet();
    __delay_ms(15);    
}
void Pen_swipe2(int set_duty){
    PWM6_DutyCycleSet(set_duty);
    PWM6_LoadBufferSet();
    __delay_ms(15);    
}


void OLED_cmd(uint8_t cmd){
I2C_Write1ByteRegister(OLED_addr,0x80,cmd);
}


void OLED_data(uint8_t dat){
I2C_Write1ByteRegister(OLED_addr,0xC0,dat);
}


void OLED_init(){
OLED_cmd(0x8D); //Set charge pump
OLED_cmd(0x14); //Enable charge pump
OLED_cmd(0xAF); //Display ON
}


void OLED_clr(){
I2C_WriteNBytes(OLED_addr, CLR_cmd, 9);//Horizontal addressing mode
for(unsigned int i = 0;i < 1024 ;i++ ){ //0s00?1024???
OLED_data(0x00);
}
}



void font6_posi(uint8_t page, uint8_t column){
Size = 0; //printf ?????putch ???????????
Page = page; // ????????font12??????????????????
Column = column; // ??????font12??????????????????
Posi_cmd[3] = 0xB0 + page; // ?????????????????? 0xB0 ???
Posi_cmd[4] = column & 0x0F; //low_column
column = column >>4;
Posi_cmd[5] = column + 0x10; //hi_column
I2C_WriteNBytes(OLED_addr, Posi_cmd, 6); //Position ?????I2C???
}


void font12_posi(uint8_t page,uint8_t column){
Size = 1; 
Page = page; 
Column = column;
Posi_cmd[3] = page + 0xB0; 
Posi_cmd[4] = column & 0x0F; 
column = column >>4;
Posi_cmd[5] = column + 0x10; 
I2C_WriteNBytes(OLED_addr, Posi_cmd, 6);
}


void chr6(uint8_t c){
c = c - 0x20;
for(uint8_t i = 0; i<6; i++){
Font6_data[i+1] = font6[c][i];
}
I2C_WriteNBytes(OLED_addr,Font6_data,7);
}


void chr12(uint8_t c){
uint8_t temp;
uint8_t i;
c = c + 6 - 0x30;
Page = Page + 0xB0;
Low_col = Column & 0x0F;
temp = Column >> 4;
Hi_col = temp + 0x10;
Posi_cmd[3] = Page;
Posi_cmd[4] = Low_col;
Posi_cmd[5] = Hi_col;
I2C_WriteNBytes(OLED_addr,Posi_cmd,6);
for(i = 0; i<12; i++){
Font12_data[i+1] = font12[c][i];
}
I2C_WriteNBytes(OLED_addr,Font12_data,13);

Page = Page + 1;
Posi_cmd[3] = Page;
I2C_WriteNBytes(OLED_addr,Posi_cmd,6);
for(i = 12; i<24; i++){
Font12_data[i-11] = font12[c][i];
}
I2C_WriteNBytes(OLED_addr,Font12_data,13);
Page = Page - 1 - 0xB0;
Column = Column +12;
}


void putch(uint8_t c){
if(Size){
chr12(c);
}else{
chr6(c);
}
}



void Time_disp(){
//OLED_clr();
font6_posi(2, 0);
printf("%02x:",REG[3]);
printf("%02x:",REG[2]);
printf("%02x",REG[1]);
}

void RTC_disp(){
font6_posi(1, 0);
printf("20");
printf("%x/",REG[7]);
printf("%x/",REG[6]);
printf("%x ",REG[5]);
printf("(%s)",week[REG[4]]);
font6_posi(2, 0);
printf("%02x:",REG[3]);
printf("%02x:",REG[2]);
printf("%02x",REG[1]);
}


void Time_Adj(int num){
    
    switch(num) {
    case 1:
        
        if(kind<7){
            kind=kind+1;
        }
        else{
            kind=7;
        }
        break;
    case 2:
        
        if(kind>2){
            kind=kind-1;
        }
        else{
            kind=2;
        }
        break;
    case 3://+1(増)        
        if (settei[kind][0] < settei[kind][2]){
            settei[kind][0]=settei[kind][0] +1;
        }

        break;
    case 4://-1(減)
        if (settei[kind][0] > settei[kind][1]){
            settei[kind][0]=settei[kind][0] -1;
        }

        break;       
    }    
}

void Alm_Adj(int num){

    switch(num) {
    case 1:
        
        if(kind<3){
            kind=kind+1;
        }
        else{
            kind=3;
        }
        break;
        
    case 2:
        
        if(kind>0){
            kind=kind-1;
        }
        else{
            kind=0;
        }
        break;
        
    case 3://+1(増)        
        if (alm_settei[kind][0] < alm_settei[kind][2]){
            alm_settei[kind][0] = alm_settei[kind][0] +1;
        }
        break;
        
    case 4://-1(減)
        if (alm_settei[kind][0] > alm_settei[kind][1]){
            alm_settei[kind][0] = alm_settei[kind][0] -1;
        }
        break;
    }    
}

void MoveServo(void){

    
    font6_posi(4, 0);
    printf("MOVE SERVO ");
    
    I2C_Write1ByteRegister(RTC_addr,CTL1,0x20);
    alm_active=false;
    
    //サーボ１
    if(alm_settei[2][0]==0 & alm_settei[3][0]==0){
        Pen_swipe(2500);
        return;
    }
    if(alm_settei[2][0]==0 & alm_settei[3][0]==1){
        Pen_swipe(1900);
        return;
    }
    
    //サーボ２
    if(alm_settei[2][0]==1 & alm_settei[3][0]==0){
        Pen_swipe2(2500);
        return;
    }
    if(alm_settei[2][0]==1 & alm_settei[3][0]==1){
        Pen_swipe2(1900);
        return;
    }
    
}

void  TMR2_Process(void){
    
    count++;
    
    
    
    //通常モード
    if(adj_mode==0){
        if(AA==true & BB==false & CC==false & DD==false){
            Pen_swipe(2500);            
        }
        if(AA==false & BB==true & CC==false & DD==false){
            Pen_swipe(1900);
        }
        if(AA==false & BB==false & CC==true & DD==false){
            Pen_swipe2(2500);
        }
        if(AA==false & BB==false & CC==false & DD==true){
            Pen_swipe2(1900);
        }
        if(AA==true & BB==false & CC==false & DD==true){
            kind=2;//分をデフォルト
            adj_mode=1;
        }
        if(AA==true & BB==false & CC==true & DD==false){
            kind=2;//分をデフォルト
            adj_mode=2;
            alm_active=false;
        }
    }
    
    //時間調整モード
    else if(adj_mode==1){
        if(AA==true & BB==false & CC==false & DD==false){            
            Time_Adj(1);
        }
        if(AA==false & BB==true & CC==false & DD==false){
            Time_Adj(2);
        }
        if(AA==false & BB==false & CC==true & DD==false){
            Time_Adj(3);
         }        
        if(AA==false & BB==false & CC==false & DD==true){
            Time_Adj(4);
        }
        if(AA==true & BB==true & CC==false & DD==false){
            adj_mode=0;
            set_flg=true;
        }

    }
    //アラーム設定モード
    else if(adj_mode==2){
        if(AA==true & BB==false & CC==false & DD==false){            
            Alm_Adj(1);
        }
        if(AA==false & BB==true & CC==false & DD==false){
            Alm_Adj(2);
        }
        if(AA==false & BB==false & CC==true & DD==false){
            Alm_Adj(3);
         }        
        if(AA==false & BB==false & CC==false & DD==true){
            Alm_Adj(4);
        }
        if(AA==true & BB==true & CC==false & DD==false){
            adj_mode=0;
            alm_set_flg=true;
        }

    }
}


void main(void)
{    
    SYSTEM_Initialize();    
    TMR2_SetInterruptHandler(TMR2_Process);
    INTERRUPT_GlobalInterruptEnable();    
    INTERRUPT_PeripheralInterruptEnable();    

    OLED_init();
    OLED_clr();

    
    Time_data_write();
    Time_data_read();
    OLED_clr();
    RTC_disp();
//    Alarm_set();
    adj_mode=0;//通常モード
    set_flg=false;    
    count=0;
//    kind=2;
    alm_active=false;

    while (1)
    {        
        //ボタンの状態をリセット
        AA=false;
        BB=false;
        CC=false;
        DD=false;

        //現在時刻を表示
        Time_data_read();
        RTC_disp();        
        
        font6_posi(5, 0);
        printf("                                                             ");
        //ボタンの状態確認
        if(TURN_OFF_GetValue()==0){
            AA=true;
            font6_posi(5, 0);
            printf("AA");
        }    
        if(TURN_ON_GetValue()==0){
            BB=true;
            font6_posi(5, 15);
            printf("BB");
        }
        if(UP_GetValue()==0){
            CC=true;
            font6_posi(5, 30);
            printf("CC");
        }
        if(DOWN_GetValue()==0){
            DD=true;
            font6_posi(5, 45);
            printf("DD");
        }
        
        //アラーム設定時間になった場合
        if(alm_active==true & INTA_GetValue()==0){
            MoveServo();
//            return;
        }
        
        //画面表示の切り替え
        if(adj_mode ==1){
            font6_posi(3, 0);
            printf("CLOCK ADJ MODE ");
            font6_posi(6, 0);
            printf("%d: %s :%d               ",kind,unit[kind],settei[kind][0]);//設定中の項目と値を表示
        }
        else if(adj_mode ==2){
            font6_posi(3, 0);
            printf("ALARM SET MODE ");
            font6_posi(6, 0);
            printf("%d: %s :%d               ",kind,unit2[kind],alm_settei[kind][0]);//設定中の項目と値を表示
        }    
        else{           
            font6_posi(3, 0);
            printf("                ");
            font6_posi(6, 0);
            printf("                ");
            if(set_flg==true){
                Clock_set();
                set_flg=false;
            }
            else if(alm_set_flg==true){
                Alarm_set();
                alm_set_flg=false;
            }
        }
        
        //アラーム設定されている場合
        if(alm_active==true){            

            font6_posi(7, 0);
            printf("%02d:%02d   %s %s               ",alm_settei[1][0],alm_settei[0][0]\
                    ,SRV[alm_settei[2][0]],DIR[alm_settei[3][0]]);//
        }                       

    }
}


