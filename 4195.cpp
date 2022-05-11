#include<cstdio>
#include<map>
#include<string>
#include<algorithm>
using namespace std;
int n;
//char in[200005][25];
int friends[200005];
int friends_ans[200005];
int friends_count;
int ans;
map<string,int> f;
/*
int find_friends(char s[]) {
    int i;
    for(i=1;i<=friends_count;++i) {
        if(strcmp(s+1,in[i]+1)==0) {
            return i;
        }
    }
    ++friends_count;
    strcpy(in[friends_count]+1,s+1);
    return friends_count;
}*/

int find_root(int a) {
    if(a==friends[a]) return a;
    return friends[a]=find_root(friends[a]);
}

void union_friends(int a,int b) {
    a=find_root(a);
    b=find_root(b);
    if(a<b) {
        friends_ans[a] += friends_ans[b];
        friends[b]=a;
    }
    else if(b<a) {
        friends_ans[b] += friends_ans[a];
        friends[a]=b;
    }
}

int main() {
    int t,i;
    char a[25],b[25];
    int t_a,t_b;
    scanf(" %d",&t);
    map<string,int>::iterator it;
    for(;t>=1;--t) {
        scanf(" %d",&n);
        friends_count=0;
        for(i=1;i<=n*2;++i) {
            friends[i]=i;
            friends_ans[i]=1;
        }
        for(i=1;i<=n;++i) {
            scanf(" %s %s",a+1,b+1);
            // t_a=find_friends(a+1);
            // t_b=find_friends(b+1);
            it=f.find(a+1);
            if(it==f.end()) {
                f[a+1]=++friends_count;
                t_a=friends_count;
            }
            else t_a=it->second;

            it=f.find(b+1);
            if(it==f.end()) {
                f[b+1]=++friends_count;
                t_b=friends_count;
            }
            else t_b=it->second;
            union_friends(t_a,t_b);
            printf("%d\n",friends_ans[find_root(t_a)]);
        }
    }
    return 0;
}