/* =====================================================================
 * Project:      PULP DSP Library
 * Title:        plp_mat_copy_stride_f32.c
 * Description:  32-bit floating-point strided matrix copy glue code
 *
 * $Date:        17. July 2020
 * $Revision:    V0
 *
 * Target Processor: PULP cores
 * ===================================================================== */
/*
 * Copyright (C) 2020 ETH Zurich and Ubiversity of Bologna. All rights reserved.
 *
 * Author: Tibor Schneider, ETH Zurich
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the License); you may
 * not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an AS IS BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "plp_math.h"

/**
   @ingroup groupMatrixStride
 */

/**
  @addtogroup MatCopyStride
  @{
 */

/**
  @brief      Glue code to copy an MxN strided 32-bit floats matrix
  @param[in]  pSrc      Points to the input matrix of shape MxN
  @param[in]  M         Height of both matrices
  @param[in]  N         Width of both matrices
  @param[in]  strideSrc Stride of the input matrix (elements between each row)
  @param[in]  strideDst Stride of the output matrix (elements between each row)
  @param[out] pDst      Points to the output matrix of shape MxN
  @return     none
 */

void plp_mat_copy_stride_f32(const float *__restrict__ pSrc,
                             uint32_t M,
                             uint32_t N,
                             uint32_t strideSrc,
                             uint32_t strideDst,
                             float *__restrict__ pDst) {

    if (rt_cluster_id() == ARCHI_FC_CID) {
        printf("Floating point is supported only for cluster side\n");
        return;
    } else {
        plp_mat_copy_stride_f32s_xpulpv2(pSrc, M, N, strideSrc, strideDst, pDst);
    }
}

/**
  @} end of MatCopyStride group
 */
