//IBM_PROLOG_BEGIN_TAG
/* 
 * Copyright 2003,2016 IBM International Business Machines Corp.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * 	http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or
 * implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
//IBM_PROLOG_END_TAG

#ifndef cipClientPyapi_h
#define cipClientPyapi_h


/**
 * @file cipClientPyapi.H
 * @brief Converged IP Systems eCMD Pyapi Extension

 * Primary Extension Owner   : Kahn Evans
 * Secondary Extension Owner : Steven Janssen

 @section cip CIP (Converged IP Systems) Extension
 This extension provides interfaces to start/stop processor instructions and breakpoint handling.<br>

 Include files :
 <ul>
 <li> cipClientPyapi.H </li>
 <li> cipStructs.H</li>
 </ul>

*/

//--------------------------------------------------------------------
// Includes
//--------------------------------------------------------------------


#include <ecmdReturnCodes.H>
#include <ecmdStructs.H>
#include <ecmdDataBuffer.H>
#include <cipStructs.H>

//--------------------------------------------------------------------
//  Forward References                                                
//--------------------------------------------------------------------


/** @name Load/Unload Functions */
//@{

/**
   @brief Initialize eCMD CIP Extension DLL
   @param i_clientVersion Comma seperated list of eCMD Python api major numbers this script supports, see details
   @retval ECMD_SUCCESS if successful load
   @retval ECMD_INVALID_DLL_VERSION if Dll version loaded doesn't match client version
   @retval nonzero if unsuccessful
   @post eCMD CIP Extension is initialized and version checked

   VERSIONS :
   eCMD at times has to make changes to add/remove functionality and parameters to functions.  This could cause
   incompatability in your script if you used functions that have changed.  The i_clientVersion string is used
   to tell eCMD which major releases you support such that your script will not continue execution if it encounters
   a version that is either not known about or not supported.  This is similar to how the eCMD C-Api works except in
   Python you can support multiple versions with one script as long as the changes that were made between the versions
   do not affect your script.

   USAGE :
   if (cipInitExtension("ver3,ver4")):
       print("ERROR: Fatal errors initializing DLL")
       sys.exit(0)
   
*/
int cipInitExtension(const char * i_clientVersion);

//@}


#endif /* cipClientCapi_h */
