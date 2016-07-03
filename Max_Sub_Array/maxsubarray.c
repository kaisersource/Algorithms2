 #include <stdio.h>
int main(){
    int s[10],a[10],m,x;
    s[0]=0;
    for (int i = 1; i < 10; ++i) {
        if(i%2==0)      //non
            a[i]=i;     //avevo
        else            //lo sbatto
            a[i]=0-i;   //per gli input
        s[i]=s[i-1]+a[i];
    }
    m=0;
    for (int i = 0; i < 10; ++i) {
        for (int j = i; j < 10; ++j) {
            x=s[j]-s[i-1];
            if(x>m){
                m=x;
            }
        }
    }
