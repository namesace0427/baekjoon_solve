#include<cstdio>

int n;
int in[1005];
int dy[1005];
int via[1005];

int main() {
    scanf("%d",&n);
    int i;
    for(i=1;i<=n;++i) {
        scanf(" %d",in+i);
    }

    int j;
    dy[1] = 1;
    via[1] = 0;
    for(i=2;i<=n;++i) {
        for(j=i-1;j>=0;--j) {
            if(in[i]>in[j] && dy[i]<=dy[j]+1) {
                dy[i]=dy[j]+1;
                via[i]=j;
                // break;
            }
        }
    }

    int max = 0, p = 0;
    for(i=1;i<=n;++i) {
        // printf("%d ",via[i]);
        if(max<=dy[i]) {
            max=dy[i];
            p=i;
        }
    }
    // printf("\n");
    printf("%d\n",max);
    int ans[1005], cnt=0;
    for(;p>0;) {
        ans[++cnt]=p;
        p=via[p];
    }
    for(;cnt>=1;--cnt) {
        printf("%d ",in[ans[cnt]]);
    }
    return 0;
}