/*******************************************************************************
 * Copyright (c) 2013, Esoteric Software
 * All rights reserved.
 * 
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 * 
 * 1. Redistributions of source code must retain the above copyright notice, this
 *    list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 ******************************************************************************/

#ifndef SPINE_SKELETONJSON_H_
#define SPINE_SKELETONJSON_H_

#include <spine/Attachment.h>
#include <spine/AttachmentLoader.h>
#include <spine/SkeletonData.h>
#include <spine/Atlas.h>
#include <spine/Animation.h>

#ifdef __cplusplus
namespace spine {
extern "C" {
#endif

typedef struct {
	float scale;
	AttachmentLoader* attachmentLoader;
	const char* const error;
} SkeletonJson;

SkeletonJson* SkeletonJson_newWithLoader (AttachmentLoader* attachmentLoader);
SkeletonJson* SkeletonJson_new (Atlas* atlas);
void SkeletonJson_free (SkeletonJson* skeletonJson);

SkeletonData* SkeletonJson_readSkeletonData (SkeletonJson* skeletonJson, const char* json);
SkeletonData* SkeletonJson_readSkeletonDataFile (SkeletonJson* skeletonJson, const char* path);

Animation* SkeletonJson_readAnimation (SkeletonJson* skeletonJson, const char* json, const SkeletonData *skeletonData);
Animation* SkeletonJson_readAnimationFile (SkeletonJson* skeletonJson, const char* path, const SkeletonData *skeletonData);

#ifdef __cplusplus
}
}
#endif

#endif /* SPINE_SKELETONJSON_H_ */