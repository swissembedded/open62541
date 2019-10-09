/* This work is licensed under a Creative Commons CCZero 1.0 Universal License.
 * See http://creativecommons.org/publicdomain/zero/1.0/ for more information.
 *
 *    Copyright 2018 (c) Jose Cabral, fortiss GmbH
 *    Copyright 2018 (c) Stefan Profanter, fortiss GmbH
 *    Copyright 2019 (c) Daniel Haensse, swissEmbedded GmbH
 */

#ifdef UA_ARCHITECTURE_FREERTOSTCP

#include <open62541/types.h>

unsigned int UA_socket_set_blocking(UA_SOCKET sockfd){
  TickType_t timeout;
  if( sockfd != FREERTOS_INVALID_SOCKET )
  {
    timeout = ipconfigSOCK_DEFAULT_RECEIVE_BLOCK_TIME;
    if(FreeRTOS_setsockopt( sockfd, 0, FREERTOS_SO_RCVTIMEO, &timeout, 0 ) )
      return UA_STATUSCODE_BADINTERNALERROR;
    timeout = ipconfigSOCK_DEFAULT_SEND_BLOCK_TIME;
    if(FreeRTOS_setsockopt( sockfd, 0, FREERTOS_SO_SNDTIMEO, &timeout, 0 ) )
      return UA_STATUSCODE_BADINTERNALERROR;
    return UA_STATUSCODE_GOOD;
  }
  return UA_STATUSCODE_BADINTERNALERROR;
}

unsigned int UA_socket_set_nonblocking(UA_SOCKET sockfd){
   TickType_t timeout = 0;
  if( sockfd != FREERTOS_INVALID_SOCKET )
  {
    if(FreeRTOS_setsockopt( sockfd, 0, FREERTOS_SO_RCVTIMEO, &timeout, 0 ) )
      return UA_STATUSCODE_BADINTERNALERROR;
    if(FreeRTOS_setsockopt( sockfd, 0, FREERTOS_SO_SNDTIMEO, &timeout, 0 ) )
      return UA_STATUSCODE_BADINTERNALERROR;
    return UA_STATUSCODE_GOOD;
  }
  return UA_STATUSCODE_BADINTERNALERROR;
}

int gethostname_freertostcp(char* name, size_t len){
  // use UA_ServerConfig_set_customHostname to set your hostname as the IP
  return -1;
}

void UA_initialize_architecture_network(void){
  return;
}

void UA_deinitialize_architecture_network(void){
  return;
}

#if UA_IPV6
  #error "IPV6 is still in experimental state, not supported yet by FreeRTOS TCP"
#endif //UA_IPV6

#endif /* UA_ARCHITECTURE_FREERTOSLWIP */
