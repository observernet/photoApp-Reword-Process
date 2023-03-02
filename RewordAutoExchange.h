#ifndef _REWORD_AUTO_EXCHANGE_H
#define _REWORD_AUTO_EXCHANGE_H

/*************************************************************************************
 * Defines....
 *************************************************************************************/

typedef struct
{
	double			auto_exchange_amount;		/* 자동환전금액 */
	char			from_address[64];			/* 환전주소 */
	char			wallet_type;				/* 주소구분 */
	char			cert_info[128];				/* 인증정보 */
} REWORD_CONFIG;

/*************************************************************************************
 * Global 변수 정의
 *************************************************************************************/
 
char				program_name[64];
int 				process_id;

sql_context			ctx;

REWORD_CONFIG		config;

char				KASConn_ip[16];
int					KASConn_port;
char				KASConn_service_name[64];
char				KASConn_account_pool[64];
SOCKET				KASConn_sockfd = -1;
struct timeval		timeover;

char				syncredis_ip[16];
int					syncredis_port;

/*************************************************************************************
 * 함수 정의
 *************************************************************************************/

int		FetchConfig();
int		ProcessAutoExchange();
int     TransferExchange(char* user_key, double obsp);
char*   SendTransferToKASConn(char* user_key, char* from_address, char* to_address, double amount, char acctype, char* cert_info);
int		ConnectKASConn();

void	InitServer();
void	interrupt(int sig);

#endif
