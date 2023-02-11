#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stack>

int const N = 5;




void cycle(int mas[][N], int n, int v[], int& count) {
    v[n] = count;
    count++;
    for (int i = 0; i < N; i++) {
        if (mas[n][i] == 1 && v[i]==0) {
            cycle(mas, i, v, count);
            v[n] = count;
            count++;
        }

    }

}


void supercycle(int mas[][N], int v[], int n) {
    v[n] = 0;

    for (int i = 0; i < N; i++) {
        if (mas[n][i] == 1 && v[i] >0 ) {
            supercycle(mas, v, i);
      
        }

    }



}




int main()
{

    int mas[N][N];
    int v[N];


    int dop[N][N];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            mas[i][j] = 0;
            dop[i][j] = 0;
            v[i] = 0;

        }
    }
    std::string m;
    std::string line;
    int k = 0;
    int r = 0;
    std::ifstream in("in.txt");
    if (in.is_open())
    {
        while (!in.eof()) {
            while (getline(in, line))
            {
                m = line;
                for (int i = 0; i < m.length(); i++) {
                    if (m[i] != ' ') {
                        dop[k][r] = dop[k][r] * 10 + (int)m[i] - 48;
                    }
                    else {
                        r++;
                    }
                }
                k++;
                r = 0;
            }
        }

    }
    in.close();
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (dop[i][j] != 0) {
                mas[i][dop[i][j] - 1] = 1;

            }

        }
    }

    int komp = 0;


    std::stack <int> gg;

    int dano = 0;
    int count = 1;



    int mastwo[N][N];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            mastwo[i][j] = mas[j][i];

        }
    }


    


     
        for (int i = 0; i < N; i++) {
            if (v[i] == 0) {
                dano = i;
                cycle(mas, dano, v, count);
                i = -1;
            }
    }


   
        while (1) {
            int ccc = 0;
            for (int i = 0; i < N; i++) {
                if (v[i] > 0) {
                    ccc++;
                }
            }

            if (ccc == 0) {
                break;
            }
            else {
                ccc = 0;
            }



            int max = 0;
            int maxi = 0;
            for (int j = 0; j < N; j++) {
                if (max < v[j]) {
                    max = v[j];
                    maxi = j;
                }
            }

            supercycle(mastwo, v, maxi);

            for (int i = 0; i < N; i++) {
                if (v[i] == 0) {

                    std::cout << i+1 << " ";
                    v[i] = -1;
                }


            }

            std::cout<< std::endl;
            komp++;

        }
       
        std::cout << std::endl;
        std::cout << komp;
 

}