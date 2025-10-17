#ifndef CUSTOMMATRIX_H
#define CUSTOMMATRIX_H
class CustomMatrix{
public:
    bool mat[3][3]={0};
    CustomMatrix(){

    }

    void fillMatrix(bool m[3][3]){
        for (int i=0;i< sizeof(m);i++) {
            for(int j=0; j < sizeof(m[0]);j++){
                mat[i][j] = m[i][j];
            }
        }
    }
};

#endif // CUSTOMMATRIX_H
