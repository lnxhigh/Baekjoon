#include<cstdio>
int X,K,i;char S[1<<17];int main(){scanf("%s",S);for(;S[i];i++)S[i]=='('?K++:X+=S[i-1]=='('?--K:K---K;printf("%d",X);}