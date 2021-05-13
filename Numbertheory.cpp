// int nod(int n){
// 	int c=0;
// 	for(int i=1;i*i<=n;i++){
// 		if(n%i==0){
// 			c+=(1+(i*i!=n));
// 		}
// 	}return c;
// }

// void factor(int n){
// 	for(int i=2;i*i<=n;i++){
// 		if(n%i==0){
// 			int c=0;
// 			while(n%i==0){
// 				n/=i;
// 				c++;
// 			}
// 			cout<<i<<' '<<c<<endl;
// 		}
// 	}if(n!=1)cout<<n<<' '<<1<<endl;
// }

// int nod(int n){
// 	int d=1;
// 	for(int i=2;i*i<=n;i++){
// 		if(n%i==0){
// 			int c=0;
// 			while(n%i==0){
// 				n/=i;
// 				c++;
// 			}
// 			d*=(c+1);
// 		}
// 	}if(n!=1)d*=2;
// 	return d;
// }
// const int mx=1e6+5;
// int f[mx];
// int main(){
// 	for(int i=1;i<mx;i++)f[i]=nod(i);
// 	int q; cin>>q; while(q--){
// 		int n; cin>>n;
// 		cout<<f[n]<<endl;
// 	}
// }

// const int mx=1e7+5;
// int f[mx];
// int main(){
// 	for(int i=1;i<mx;i++){
// 		for(int j=i;j<mx;j+=i){
// 			f[j]++;
// 		}
// 	}
// 	int q; cin>>q; while(q--){
// 		int n; cin>>n;
// 		cout<<f[n]<<endl;
// 	}
// }
// 2^3*3^5*5^2
// int sum=0;
// for(int i=0;i<=3;i++){
// 	for(int j=0;j<=5;j++){
// 		for(int k=0;k<=2;k++){
// 			sum+=2^i * 3^j * 5^k;
// 		}
// 	}
// }

// #define ll long long
// int sod(int n){
// 	ll d=1;
// 	for(int i=2;i*i<=n;i++){
// 		if(n%i==0){
// 			int c=0;
// 			while(n%i==0){
// 				n/=i;
// 				c++;
// 			}
// 			// d*=(i^0+i^1+i^2+...+i^c);
// 			d*=(pow(i,c+1)-1)/(i-1);
// 		}
// 	}if(n!=1)d*=(1+n);
// 	return d;
// }

// const int mx=1e7+5;
// int f[mx];
// int main(){
// 	for(int i=1;i<mx;i++){
// 		for(int j=i;j<mx;j+=i){
// 			f[j]+=i;
// 		}
// 	}
// 	int q; cin>>q; while(q--){
// 		int n; cin>>n;
// 		cout<<f[n]<<endl;
// 	}
// }


const int mx=1e7+5;
int f[mx];
int main(){
	f[1]=f[0]=1;
	for(int i=4;i<mx;i+=2)f[i]=1;
	for(int i=3;i*i<=mx;i+=2){
		if(f[i]==0){
			for(int j=i*i;j<mx;j+=i+i){
				f[j]=1;
			}
		}
	}
	int q; cin>>q; while(q--){
		int n; cin>>n;
		if(f[n])printf("not prime\n");
		else printf("prime\n");
	}
}

// mathbugs.me -> basic modular arithmetic , 

// 5^30
// 5*5*5.....*5
// (5^15)^2 -> (5*5*5*5*...*5)=x x*x
// (5^7)=x x*x=5^14 * 5 = 5^15
// 5^3=x x*x=5^6 *5 =5^7
int Pow(int n,int p){
	if(p==0)return 1;
	int x=Pow(n,p/2);
	x=x*x;
	if(p%2==1)x=x*n;
	return x;
}

int Pow(int a,int b){
	int r=1;
	while(b){
		if(b%2==1)r=r*a;
		a=a*a;
		b/=2;
	}return r;
}

// progkriya number theory
