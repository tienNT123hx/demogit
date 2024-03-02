#include<iostream> 
using namespace std;
class Array{
	int n;
	int *data;
	public:
		Array(int n_, int d=0){
			n=n_;
			data=new int[n];
			for(int i=0;i<n;i++){
				data[i]=d;
			}
		}
		~Array(){
			delete [] data;
		}
		Array(const Array &a){
			n=a.n;
			data=new int[n];
			for(int i=0;i<n;i++){
				data[i]=a.data[i];
			}
		}
		Array& operator=(const Array &a){
			if(n!=a.n)
			delete [] data;
			for(int i=0;i<n;i++){
				data[i]=a.data[i];
			}
			
		}
		void nhap(){
			for(int i=0;i<n;i++){
				cin>>data[i];
			}
		}
		void xuat(){
			for(int i=0;i<n;i++){
				cout<<data[i]<<" ";
			}
			cout<<endl;
		}
		void gan(int &m, int i){ 
		if(i>=0 && i<n)
		data[i]=m;	
		else cout<<"error!"<<endl;	
		}
		int lay(int j){
			if(j>=0 && j<n)
			return data[j];
			else cout<<"error"<<endl;
			
		}
};
int main(){
	int n;cin>>n;
	Array a(n);
	a.nhap();
	a.xuat();
	
    Array b(a);
    cout<<"mang b sau khi sao chep tu a la:"<<endl;
    b.xuat();
    
    Array c(n);
    c=b;
    cout<<"mang c sau khi gan tu b la: "<<endl;
    c.xuat();
    
    int m=9,i;cout<<"nhap chi so cua phan tu:"<<endl;cin>>i;
    a.gan(m,i);
    cout<<"gia tri cua phan tu thu "<<i<<" sau khi gan la: "<<a.lay(i)<<endl;
	
	
	
}
