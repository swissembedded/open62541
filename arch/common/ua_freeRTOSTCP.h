/* This work is licensed under a Creative Commons CCZero 1.0 Universal License.
 * See http://creativecommons.org/publicdomain/zero/1.0/ for more information.
 *
 *    Copyright 2018 (c) Jose Cabral, fortiss GmbH
 *    Copyright 2019 (c) Daniel Haensse, swissEmbedded GmbH
 */

#ifndef ARCH_COMMON_FREERTOSTCP62541_H_
#define ARCH_COMMON_FREERTOSTCP62541_H_

 
#include "FreeRTOS_sockets.h"

#define OPTVAL_TYPE int

#define UA_fd_set(fd, fds) FD_SET((unsigned int)fd, fds)
#define UA_fd_isset(fd, fds) FD_ISSET((unsigned int)fd, fds)

#define UA_SOCKET Socket_t
#define UA_INVALID_SOCKET FREERTOS_INVALID_SOCKET 
#define UA_ERRNO errno
#define UA_INTERRUPTED EINTR
#define UA_AGAIN EAGAIN
#define UA_EAGAIN EAGAIN
#define UA_WOULDBLOCK EWOULDBLOCK
#define UA_ERR_CONNECTION_PROGRESS EINPROGRESS

#define UA_send FreeRTOS_send
#define UA_recv FreeRTOS_recv
#define UA_sendto FreeRTOS_sendto
#define UA_recvfrom FreeRTOS_recvfrom
#define UA_htonl FreeRTOS_htonl
#define UA_ntohl FreeRTOS_ntohl
#define UA_close FreeRTOS_close
#define UA_select FreeRTOS_select
#define UA_shutdown FreeRTOS_shutdown
#define UA_socket FreeRTOS_socket
#define UA_bind FreeRTOS_bind
#define UA_listen FreeRTOS_listen
#define UA_accept FreeRTOS_accept
#define UA_connect FreeRTOS_connect
//#define UA_getsockopt FreeRTOS_getsockopt
#define UA_setsockopt FreeRTOS_setsockopt
//#define UA_freeaddrinfo FreeRTOS_freeaddrinfo
#define UA_gethostname gethostname_freertostcp
//#define UA_getsockname FreeRTOS_getsockname
//#define UA_getaddrinfo FreeRTOS_getaddrinfo

#if UA_IPV6
  #error "IPV6 is still in experimental state, not supported yet by FreeRTOS TCP"
#else
# define UA_inet_pton(af, src, dst) \
     if((af) == AF_INET)
     {
      *(dst)=FreeRTOS_inet_addr(src);
     }
     else
     {
         *(dst)=0;
     }
#endif


int gethostname_freertostcp(char* name, size_t len); //gethostname is not present in FreeRTOS plus. We implement here a dummy. See ../freertosTCP/ua_architecture_functions.c

#define UA_LOG_SOCKET_ERRNO_GAI_WRAP UA_LOG_SOCKET_ERRNO_WRAP

#endif /* ARCH_COMMON_FREERTOSTCP62541_H_ */
