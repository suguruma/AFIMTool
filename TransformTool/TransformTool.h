//=====================================================================//
//  �t�@�C���� : TransformTool.h	                                   //
//=====================================================================//
#pragma once
namespace TransformTool {
	//-- �ϐ��錾(����) --//
	int point_max;						// �S�Ă̓_�̐�(1-103)
	int iWidth, iHeight;				// ����,�c��
	int oWidth, oHeight;				// ����,�c��
	int in_point_size, out_point_size;	// �_�̑傫��
	int in_pt_counter, out_pt_counter;	// �_�̐����J�E���g
	//-- �ϐ��錾(Affine) --//
	int startX, startY, endX, endY;		// �X�L�����J�n�ʒu:(x,y)
	int moph_counter, moph_max = 96; // �ό`��					
	int in_moph_counter, out_moph_counter;
	// �O�p�p�b�`(�\����)�̐�
	struct ThreePoint{
		int px[3]; 	// x���W
		int py[3];	// y���W
	};
	struct ThreePoint *ip, *op;
	struct ThreePoint *tmpip, *tmpop;

	//-- �ϐ��錾(Spline) --//
	double B[4];
	int latbw;
	int latw, lath;
	int itmp;	// �ꎞ�ۑ�
	int x_dtmp, y_dtmp;
	double s, t;
	double W[4][4];
	double Wab;
	double x_fai[4][4];
	double y_fai[4][4];
	double omega;
	int transform_frame;
	int current_pt;


	// �t���O�Z�b�g
	struct FlagSet
	{
		int read;	// �ǂݍ��݊m�F
		int ipmesh;	// ���̓��b�V���\��
		int opmesh;	// �o�̓��b�V���\��
		int point;	// �蓮�_����
		int prep;
		int finish;	// �S�Ă̏���������
		int num;	// ������\��
		int direction;  // �z�C�[���̕���
		int pprint;	// �_�̕\��
		int intext;
		int outtext;
	};
	struct FlagSet flagSet;

	// ���[�t�B���O����
	int refOrIndex;			// �Q�ƌ��C���f�b�N�X
	int refAhIndex;			// �Q�Ɛ�C���f�b�N�X
	//int iWidth, iHeight;	// ����,�c��
	int refOrX, refOrY;		// �Q�ƌ����W
	double refAhX, refAhY;	// �Q�Ɛ���W

	//--�ϐ��錾--// 
	struct controlLattice { // 3(����,�o��)���W�_
		double xdel;
		double ydel;
		double xfai;
		double yfai;
		double ome;
	}*cl;

	int inw,inh;
	double fx,fy;

	//-- �v���g�^�C�v�錾 --//
	void BilinearInterpolation(double inx, double iny, int outx, int outy);
}


