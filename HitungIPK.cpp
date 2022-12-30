#include <iostream>

using namespace std;

const int nMax = 10;

typedef string arrMK[nMax];
typedef int arrSKS[nMax];
typedef string arrIdx[nMax];

struct dataMK {
    arrMK tabMK;
    arrSKS tabSKS;
    arrIdx tabIdx;
    int N;
};

float getPoint(string index) {
    if (index == "A") {
        return 4;
    } else if (index == "AB") {
        return 3.5;
    } else if (index == "B") {
        return 3; 
    } else if (index == "BC") {
        return 2.5;
    } else if (index == "C") {
        return 2;
    } else if (index == "D") {
        return 1;
    } else {
        return 0;
    }
}

float Poin(int SKS, float point) {
    return SKS*point;
}

float totalPoin(dataMK dataCourse) {
    float t_poin = 0;

    for (int i = 0; i < dataCourse.N; i++) {
        t_poin = t_poin + Poin(dataCourse.tabSKS[i], getPoint(dataCourse.tabIdx[i]));
    }
    return t_poin;
}


void inputData(dataMK &dataCourse) {
    for (int i = 0; i < dataCourse.N; i++) {
        cout << "[" << i+1 << "]" << endl;
        cout << "Mata Kuliah : ";
        cin >> dataCourse.tabMK[i];
        cout << "SKS         : ";
        cin >> dataCourse.tabSKS[i];
        cout << "Index Nilai : ";
        cin >> dataCourse.tabIdx[i];
        cout << endl;
    }
}

int totalSKS(dataMK dataCourse) {
    int t_sks = 0;
    for (int i = 0; i < dataCourse.N; i++) {
        t_sks = t_sks + dataCourse.tabSKS[i];
    }
    return t_sks;    
}

float finalIPK(dataMK dataCourse){
    return totalPoin(dataCourse) / totalSKS(dataCourse);
}

int main() {
    dataMK MK;
    
    cout << "Jumlah Mata Kuliah = ";
    cin >> MK.N;

    inputData(MK);
    cout << "IPK = " << finalIPK(MK) << endl;

}

