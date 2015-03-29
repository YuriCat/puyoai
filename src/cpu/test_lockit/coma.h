#ifndef CPU_TEST_LOCKIT_COMA_H_
#define CPU_TEST_LOCKIT_COMA_H_

#include "lockit_constant.h"

/* for TAIOU TYPE?
int q_t=1;
int w_t=1;
int e_t=0;
int r_t=1;
int t_t=1;
int y_t=3;
int u_t=1;
int i_t=0;
int o_t=0;
int p_t=3;
int a_t=1;*/

const int tubushiturn = 13;
// int tubushiturn = 99999;
const int saisoku_point = 1;
// int saisoku_point = 0;

class COMAI_HI {
private:
public:
    COMAI_HI();
    ~COMAI_HI();

    int saiki(int[][TAT_SIZE], int[][12], int, int, int*, int);
    int saiki_right(int[][TAT_SIZE], int[][12], int, int, int*, int);
    int saiki_left(int[][TAT_SIZE], int[][12], int, int, int*, int);
    int saiki_up(int[][TAT_SIZE], int[][12], int, int, int*, int);
    int saiki_down(int[][TAT_SIZE], int[][12], int, int, int*, int);

    int saiki_3(int[][TAT_SIZE], int[][12], int, int, int*, int);
    int saiki_3_right(int[][TAT_SIZE], int[][12], int, int, int*, int);
    int saiki_3_left(int[][TAT_SIZE], int[][12], int, int, int*, int);
    int saiki_3_up(int[][TAT_SIZE], int[][12], int, int, int*, int);
    int saiki_3_down(int[][TAT_SIZE], int[][12], int, int, int*, int);

    int saiki_4(int[][TAT_SIZE], int, int, int*, int);

    int syou(int[][TAT_SIZE], int, int, int, int[]);
    int syou_right(int[][TAT_SIZE], int, int, int, int[]);
    int syou_left(int[][TAT_SIZE], int, int, int, int[]);
    int syou_up(int[][TAT_SIZE], int, int, int, int[]);
    int syou_down(int[][TAT_SIZE], int, int, int, int[]);
    int syou_downx(int[][TAT_SIZE], int, int, int, int[], int*);
    int syou_right_num(int[][TAT_SIZE], int, int, int, int[], int*);
    int syou_left_num(int[][TAT_SIZE], int, int, int, int[], int*);
    int syou_up_num(int[][TAT_SIZE], int, int, int, int[], int*);
    int syou_down_num(int[][TAT_SIZE], int, int, int, int[], int*);
    int syou_2(int[][TAT_SIZE], int, int, int);

    int tobashi_hantei_a(int[][TAT_SIZE], int, int, int);
    void putPuyos(int[][TAT_SIZE], int, int, int, int[]);
    int tobashi_hantei_b(int[][TAT_SIZE], int);
    int chousei_syoukyo(int[][TAT_SIZE], int[]);
    int chousei_syoukyo_2(int[][TAT_SIZE], int[], int*, int[], int*, int*);
    int chousei_syoukyo_3(int[][TAT_SIZE], int[], int*, int*, int, int, int);
    int chousei_syoukyo_sc(int[][TAT_SIZE], int[], int*);

    // Simulate Puyo behaviors in |field| and returns the number of
    // combo(連鎖数).  |score| figures the expected score in the chain,
    // and |quick| is 1(true) if no puyos fall after the last vanishment.
    int simulateChain(int field[][TAT_SIZE], int* score, int* quick);

    int setti_puyo_1(int[][TAT_SIZE], int, int);

    // Judge given filed matches with GTR template.
    int gtr(int field[][TAT_SIZE]);

    int aite_hyouka(int ba3[][TATE], int nex, int nex2, int nnx, int nnx2);
    int pre_hyouka(int ba3[6][TATE], int nex, int nex2, int nnx, int nnx2, int zenkesi_own, int aite_ba[6][TATE],
                   int zenkesi_aite, int fast);
    int hyouka(int ba3[6][TATE], int nex, int nex2, int nnx, int nnx2, int zenkesi_own, int aite_ba[6][TATE],
               int zenkesi_aite);
    bool isEnemyStartRensa(int ba3[6][TATE], int zenkesi_aite, int scos, int hakata);
    void aite_attack_nokori(int hakata);
    void aite_rensa_end();
    void ref();

    int read_template();

    int cchai;
    int hukks;
    int conaa, nexaa;
    int maxchais;
    int aite_rensa_score; // aite
    int aite_rensa_score_cc; // aite
    int para[22];
    int myf_kosuu;
    int saisoku_flag;
    int aite_hakka_rensa;
    int aite_hakka_nokori;
    int aite_hakka_zenkesi;
    int aite_hakka_kosuu;  // 相手が連鎖で使うぷよの個数
    int nocc_aite_rensa_score;
    int max_ee;
    int key_ee;

    int aite_hakkaji_score;
    int aite_hakka_jamako;
    int aite_hakka_honsen;
    int aite_hakka_quick;
    int moni_kesiko[3];
    int moni_iroko[3];
    int aite_puyo_uki;
    int kuraichk_mon;
    int score_mon;
    int tesuu_mon;
    int kougeki_on;
    int kougeki_edge;
    int kougeki_iryoku;

    int numg;
    int katax[TM_TMNMUM][TM_COLNUM][TM_COLPER];
    int katay[TM_TMNMUM][TM_COLNUM][TM_COLPER];
    int kko[TM_TMNMUM][TM_COLNUM];
    int colko[TM_TMNMUM];
    int colscore[TM_TMNMUM][TM_COLNUM];
    int kinko[TM_TMNMUM];
    int kinsi_a[TM_TMNMUM][TM_KINPT], kinsi_b[TM_TMNMUM][TM_KINPT];
    int jakkinko[TM_TMNMUM];
    int jakkin_a[TM_TMNMUM][TM_JAKKINPT], jakkin_b[TM_TMNMUM][TM_JAKKINPT];
    int tankinx[TM_TMNMUM][TM_TANKINPT];
    int tankiny[TM_TMNMUM][TM_TANKINPT];
    int tankinko[TM_TMNMUM];
    int jatax[TM_TMNMUM][TM_OBJE];
    int jatay[TM_TMNMUM][TM_OBJE];
    int jatako[TM_TMNMUM];
    int tm_turn[TM_TMNMUM];
    int tm_moni;
    int one_tanpatu;
    int score_max;
    int mmmax;
    int score_aa;
    int aa_max_score;
    int hakkatime;
};

#endif
