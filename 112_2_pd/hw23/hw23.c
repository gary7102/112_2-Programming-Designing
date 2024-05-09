typedef enum scoreType_s{G,GPA,S}scoreType_t;

typedef enum G_s{Aplus,A,Aduce,Bplus,B,Bduce,Cplus,C,Cduce,F,X}G_t;

typedef enum GPA_s{b4dot3,b4dot0,b3dot7,b3dot3,b3dot0,b2dot7,b2dot3,b2dot0,b1dot7,b1,b0}GPA_t;

typedef enum S_s{b90to100,b85to89,b80to84, b77to79,b73to76,b70to72,b67to69,b63to66,b60to62,b1to59,b0to0}S_t;

typedef union student_s{
    int score;
    G_t G;
    GPA_t GPA;
    S_t S;
} student_t;

void main(){
    
}