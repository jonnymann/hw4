#include <fstream>
#include <string>
#include <iostream>

using namespace std;

void print_f(double* p, const int N, const string newfile){
ofstream out(newfile.c_str());
for (int i = 0; i < N; i++)
    out << p[i] << endl;
out.close();
}

void reading(double* p, const int N, const string fname){
ifstream in(fname.c_str());
for (int i = 0; i < N; i++)
    in >> p[i];
in.close();
}

void filter(double* p, const int N){
    double p0=p[0];
    
    double x_1=p[N-1];
    double x0=p[0];
    
    for (int i=0; i<N-1;i++){
        p[i]=(x_1+x0+p[i+1])/3;
        x_1=x0;
        x0=p[i+1];
    }
    p[N-1]=(x_1+x0+p0)/3;
}

int main(){
    const string filename = "noisy.txt";
    const int N=237;
    double* p = new double[N];
    const string newfilename = "filtered.txt";
    
    reading(p, N, filename);
    filter(p,N);
    
    print_f(p,N,newfilename);
    
    delete[] p;
 
    
}