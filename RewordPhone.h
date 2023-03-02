#ifndef _REWORD_PHONE_H
#define _REWORD_PHONE_H

/*************************************************************************************
 * Defines....
 *************************************************************************************/

#define MAX_LABEL_COUNT         50

typedef struct
{
	int				reword_idx;				/* 보상키 */
	int				reword_date;			/* 보상일 */
	int				target_date;			/* 보상대상일 */
	double			rp_snap;				/* 스냅 RP */
	double			rp_label;				/* 라벨 RP */
	double			rp_label_etc;			/* 기타라벨 RP */
	double			obsp_per_day;			/* 하루보상 총 OBSP */
} REWORD_CONFIG;

typedef struct
{
	char			user_key[32];			/* 유저키 */
	int				count_snap;				/* 스냅수 */
	int				count_label;			/* 라벨수 */
	int				count_label_etc;		/* 기타라벨수 */
	double			rp_snap;				/* 스냅RP */
	double			rp_label;				/* 라벨RP */
	double			rp_label_etc;			/* 기타라벨RP */
} REWORD_USER;


// 라벨 보상을 위한 정보들....
typedef struct
{
	char			string[8];
	int				count;
} SLABEL;

typedef struct
{
	int				label_idx;				/* 라벨키 */
	char			is_today;				/* 당일여부 (Y/N) */
	char			slabel[8];				/* 라벨스트링 */
	char			is_etc;					/* 기타라벨여부 (Y/N) */
	char			slabel_etc[8];			/* 기타라벨스트링 */
} LABEL;

typedef struct
{
	int				snap_date;				/* 스냅키 */
	int				snap_idx;				/* 스냅키 */

	int				label_count;			/* 라벨갯수 */
	LABEL			label[MAX_LABEL_COUNT];	/* 라벨 */

	int				slabel_count;			/* 라벨 갯수 */
	SLABEL			slabel[8];				/* 라벨스트링 */
	int				slabel_pass_idx;		/* 해당 INDEX까지의 slabel은 패스다 */

	int				slabel_etc_count;		/* 기타라벨 갯수 */
	SLABEL			slabel_etc[8];			/* 기타라벨스트링 */
	int				slabel_etc_pass_idx;	/* 해당 INDEX까지의 slabel_etc은 패스다 */
} SNAP;

/*************************************************************************************
 * Global 변수 정의
 *************************************************************************************/
 
char				program_name[64];
int 				process_id;
long				input_time;

sql_context			ctx;

REWORD_CONFIG		config;

int					snap_count;
SNAP*				snap;

int					user_count;
REWORD_USER*		user;

char				syncredis_ip[16];
int					syncredis_port;

/*************************************************************************************
 * 함수 정의
 *************************************************************************************/

int		FetchConfig();
int		FetchTodayLabelAndCalcPass();
int		UpdateRewordPoint();
int		FetchRewordUser();
int		RewordOBSP();

void	CompleteReword();
void	UpdateUserInfoRedis();

void	InitServer();
void	interrupt(int sig);

#endif
