#include<cstdio>
int n;
int in[25][25];
int start[20];
int link[20];
int ans=1987654321;

int abs(int a) {
    return a>0?a:-a;
}

void back(int len,int st_cnt,int link_cnt) {
    if(len==n+1) {
        if(st_cnt!=n/2) return;
        int i,j,sum1,sum2,p=0;
        sum1=0;
        for(i=1;i<=n/2;++i) {
            for(j=1;j<=n/2;++j) {
                sum1+=in[start[i]][start[j]];
            }
        }
        sum2=0;
        for(i=1;i<=n/2;++i) {
            for(j=1;j<=n/2;++j) {
                sum2+=in[link[i]][link[j]];
            }
        }
        ans=ans<abs(sum1-sum2)?ans:abs(sum1-sum2);
        return;
    }
    start[st_cnt+1]=len;
    back(len+1,st_cnt+1,link_cnt);
    link[link_cnt+1]=len;
    back(len+1,st_cnt,link_cnt+1);
}

int main() {
    int i,j;
    scanf(" %d",&n);
    for(i=1;i<=n;++i) {
        for(j=1;j<=n;++j) {
            scanf(" %d",in[i]+j);
        }
    }
    back(1,0,0);
    printf("%d",ans);
    return 0;
}