#include <cstdio>
int n,in[500005];
struct data {
    int pos;
    int val;
} stack[500005];
int cnt;

int main() {
    scanf(" %d",&n);
    int i;
    for(i=1;i<=n;++i) {
        scanf(" %d",in+i);
    }
    for(i=1;i<=n;++i) {
        while(cnt>0) {
            if(stack[cnt].val>=in[i]) {
                printf("%d ",stack[cnt].pos);
                break;
            }
            --cnt;
        }
        if(cnt==0) {
            printf("0 ");
        }
        ++cnt;
        stack[cnt].val=in[i];
        stack[cnt].pos=i;
    }
    return 0;
}