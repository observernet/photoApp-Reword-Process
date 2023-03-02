#ifndef _REWORD_WS_H
#define _REWORD_WS_H

/*************************************************************************************
 * Defines....
 *************************************************************************************/

#define LENGTH_SIZE         5

typedef struct
{
	int				reword_idx;				/* 보상키 */
	int				reword_week;			/* 보상요일 */
	int				reword_date;			/* 보상일 */
	int				target_date;			/* 보상대상일 */
} REWORD_CONFIG;

typedef struct
{
	int				series;					/* 보상회차 */
	int				base;					/* 보상기준(시간) */
	long			basetime;				/* 보상기준시간(환산) */
	double			amount;					/* 보상수량 */
} SERIES_INFO;

typedef struct
{
	long			serial_no;
	long			last_observ_time;
	int				count_data;
	char			user_key[32];
} MWS_INFO;

typedef struct
{
	char			user_key[32];			/* 유저키 */
} REWORD_USER;

/*************************************************************************************
 * Global 변수 정의
 *************************************************************************************/
 
char				program_name[64];
int 				process_id;
long				input_time;

sql_context			ctx;
sql_context			ctx_data;

REWORD_CONFIG		config;

int					series_count;
SERIES_INFO*		series;

int					user_count = 0;
REWORD_USER*		user = NULL;

char				syncredis_ip[16];
int					syncredis_port;

/*************************************************************************************
 * 함수 정의
 *************************************************************************************/

int		FetchConfig();
int		FetchSeries();
int		RewordOBSP(int sidx);

void	CompleteReword();
void	UpdateUserInfoRedis();

void	InitServer();
void	interrupt(int sig);

#endif
