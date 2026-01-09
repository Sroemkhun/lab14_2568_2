#include<iostream>
using namespace std;

const int N = 5;

void inputMatrix(double A[N][N]) {
    for (int i = 0; i < N; i++) {
        cout << "Row " << i + 1 << ": "; 
        for (int j = 0; j < N; j++) {
            cin >> A[i][j];
        }
    }
}
void findLocalMax(double A[N][N], bool B[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == 0 || i == N - 1 || j == 0 || j == N - 1) {
                B[i][j] = false;
            } 
            else {
                bool isMax = (A[i][j] >= A[i-1][j]) && // Top
                             (A[i][j] >= A[i+1][j]) && // Bottom
                             (A[i][j] >= A[i][j-1]) && // Left
                             (A[i][j] >= A[i][j+1]);   // Right
                B[i][j] = isMax;
            }
        }
    }
}
void showMatrix(bool A[N][N]){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
        cout << A[i][j] << " ";
        }
        cout << endl;
    }
};

int main(){
	double A[N][N]; 
	bool B[N][N]; 
	cout << "Input the matrix.....\n";
	inputMatrix(A);
	findLocalMax(A,B);
	cout << "Result is \n";
	showMatrix(B);
	return 0;
}

//Do not modify source code above this line 
