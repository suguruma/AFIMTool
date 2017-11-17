//=====================================================================//
//  ファイル名 : TransformTool.h	                                   //
//=====================================================================//
#pragma once
namespace TransformTool {
	//-- 変数宣言(共通) --//
	int point_max;						// 全ての点の数(1-103)
	int iWidth, iHeight;				// 横幅,縦幅
	int oWidth, oHeight;				// 横幅,縦幅
	int in_point_size, out_point_size;	// 点の大きさ
	int in_pt_counter, out_pt_counter;	// 点の数をカウント
	//-- 変数宣言(Affine) --//
	int startX, startY, endX, endY;		// スキャン開始位置:(x,y)
	int moph_counter, moph_max = 96; // 変形回数					
	int in_moph_counter, out_moph_counter;
	// 三角パッチ(構造体)の数
	struct ThreePoint{
		int px[3]; 	// x座標
		int py[3];	// y座標
	};
	struct ThreePoint *ip, *op;
	struct ThreePoint *tmpip, *tmpop;

	//-- 変数宣言(Spline) --//
	double B[4];
	int latbw;
	int latw, lath;
	int itmp;	// 一時保存
	int x_dtmp, y_dtmp;
	double s, t;
	double W[4][4];
	double Wab;
	double x_fai[4][4];
	double y_fai[4][4];
	double omega;
	int transform_frame;
	int current_pt;


	// フラグセット
	struct FlagSet
	{
		int read;	// 読み込み確認
		int ipmesh;	// 入力メッシュ表示
		int opmesh;	// 出力メッシュ表示
		int point;	// 手動点完了
		int prep;
		int finish;	// 全ての処理を完了
		int num;	// 数字を表示
		int direction;  // ホイールの方向
		int pprint;	// 点の表示
		int intext;
		int outtext;
	};
	struct FlagSet flagSet;

	// モーフィング処理
	int refOrIndex;			// 参照元インデックス
	int refAhIndex;			// 参照先インデックス
	//int iWidth, iHeight;	// 横幅,縦幅
	int refOrX, refOrY;		// 参照元座標
	double refAhX, refAhY;	// 参照先座標

	//--変数宣言--// 
	struct controlLattice { // 3(入力,出力)座標点
		double xdel;
		double ydel;
		double xfai;
		double yfai;
		double ome;
	}*cl;

	int inw,inh;
	double fx,fy;

	//-- プロトタイプ宣言 --//
	void BilinearInterpolation(double inx, double iny, int outx, int outy);
}


