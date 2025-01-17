/*
 * Copyright (c) 2010 SURFnet bv
 * Copyright (c) 2010 .SE (The Internet Infrastructure Foundation)
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE
 * GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER
 * IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
 * IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/*****************************************************************************
 BotanCryptoFactory.cpp

 This is a Botan based cryptographic algorithm factory
 *****************************************************************************/
#include "config.h"
#include "BotanCryptoFactory.h"
#include "BotanAES.h"
#include "BotanDES.h"
#include "BotanDSA.h"
#include "BotanDH.h"
#ifdef WITH_ECC
#include "BotanECDH.h"
#include "BotanECDSA.h"
#endif
#include "BotanMD5.h"
#include "BotanRNG.h"
#include "BotanRSA.h"
#include "BotanSHA1.h"
#include "BotanSHA224.h"
#include "BotanSHA256.h"
#include "BotanSHA384.h"
#include "BotanSHA512.h"
#ifdef WITH_GOST
#include "BotanGOST.h"
#include "BotanGOST2012.h"
#include "BotanGOST2012_512.h"
#include "BotanGOSTR3411.h"
#include "BotanGOSTR3411_12_256.h"
#include "BotanGOSTR3411_12_512.h"
//#include "../object_store/OSObject.h"
//#include "../slot_mgr/Token.h"
#include <botan/ber_dec.h>
#endif
#include "BotanMAC.h"
#ifdef WITH_EDDSA
#include "BotanEDDSA.h"

#include <botan/ber_dec.h>
#endif

// Constructor
BotanCryptoFactory::BotanCryptoFactory()
{
	// Create mutex
	rngsMutex = MutexFactory::i()->getMutex();
}

// Destructor
BotanCryptoFactory::~BotanCryptoFactory()
{
	// Delete the RNGs
#ifdef HAVE_PTHREAD_H
	std::map<pthread_t,RNG*>::iterator it;
	for (it=rngs.begin(); it != rngs.end(); it++)
	{
		delete (BotanRNG*)it->second;
	}
#elif _WIN32
	std::map<DWORD,RNG*>::iterator it;
	for (it=rngs.begin(); it != rngs.end(); it++)
	{
		delete (BotanRNG*)it->second;
	}
#endif

	// Delete the mutex
	MutexFactory::i()->recycleMutex(rngsMutex);
}

// Return the one-and-only instance
BotanCryptoFactory* BotanCryptoFactory::i()
{
	if (!instance.get())
	{
		instance.reset(new BotanCryptoFactory());
	}

	return instance.get();
}

// This will destroy the one-and-only instance.
void BotanCryptoFactory::reset()
{
	instance.reset();
}

// Create a concrete instance of a symmetric algorithm
SymmetricAlgorithm* BotanCryptoFactory::getSymmetricAlgorithm(SymAlgo::Type algorithm)
{
	switch (algorithm)
	{
		case SymAlgo::AES:
        	        return new BotanAES();
		case SymAlgo::DES:
		case SymAlgo::DES3:
	                return new BotanDES();
		default:
	                // No algorithm implementation is available
        	        ERROR_MSG("Unknown algorithm '%i'", algorithm);

                	return NULL;
	}

	// No algorithm implementation is available
	return NULL;
}

// Create a concrete instance of an asymmetric algorithm
AsymmetricAlgorithm* BotanCryptoFactory::getAsymmetricAlgorithm(AsymAlgo::Type algorithm)
{
	switch (algorithm)
	{
		case AsymAlgo::RSA:
			return new BotanRSA();
		case AsymAlgo::DSA:
			return new BotanDSA();
		case AsymAlgo::DH:
			return new BotanDH();
#ifdef WITH_ECC
		case AsymAlgo::ECDH:
			return new BotanECDH();
		case AsymAlgo::ECDSA:
			return new BotanECDSA();
#endif
#ifdef WITH_GOST
		case AsymAlgo::GOST:
			return new BotanGOST();
		case AsymAlgo::GOST2012:
			return new BotanGOST2012();
		case AsymAlgo::GOST2012_512:
			return new BotanGOST2012_512();
#endif
#ifdef WITH_EDDSA
		case AsymAlgo::EDDSA:
			return new BotanEDDSA();
#endif
		default:
			// No algorithm implementation is available
			ERROR_MSG("Unknown algorithm '%i'", algorithm);

			return NULL;
	}

	// No algorithm implementation is available
	return NULL;
}

// Create a concrete instance of a hash algorithm
HashAlgorithm* BotanCryptoFactory::getHashAlgorithm(HashAlgo::Type algorithm)
{
	switch (algorithm)
	{
		case HashAlgo::MD5:
			return new BotanMD5();
		case HashAlgo::SHA1:
			return new BotanSHA1();
		case HashAlgo::SHA224:
			return new BotanSHA224();
		case HashAlgo::SHA256:
			return new BotanSHA256();
		case HashAlgo::SHA384:
			return new BotanSHA384();
		case HashAlgo::SHA512:
			return new BotanSHA512();
#ifdef WITH_GOST
		case HashAlgo::GOST:
			return new BotanGOSTR3411();
		case HashAlgo::GOST2012_256:
			return new BotanGOSTR3411_12_256();
		case HashAlgo::GOST2012_512:
			return new BotanGOSTR3411_12_512();
#endif
		default:
			// No algorithm implementation is available
			ERROR_MSG("Unknown algorithm '%i'", algorithm);

			return NULL;
	}

	// No algorithm implementation is available
	return NULL;
}

// Create a concrete instance of a MAC algorithm
MacAlgorithm* BotanCryptoFactory::getMacAlgorithm(MacAlgo::Type algorithm)
{
	switch (algorithm)
	{
		case MacAlgo::HMAC_MD5:
			return new BotanHMACMD5();
		case MacAlgo::HMAC_SHA1:
			return new BotanHMACSHA1();
		case MacAlgo::HMAC_SHA224:
			return new BotanHMACSHA224();
		case MacAlgo::HMAC_SHA256:
			return new BotanHMACSHA256();
		case MacAlgo::HMAC_SHA384:
			return new BotanHMACSHA384();
		case MacAlgo::HMAC_SHA512:
			return new BotanHMACSHA512();
#ifdef WITH_GOST
		case MacAlgo::HMAC_GOST:
			return new BotanHMACGOSTR3411();
#endif
		case MacAlgo::CMAC_DES:
			return new BotanCMACDES();
		case MacAlgo::CMAC_AES:
			return new BotanCMACAES();
		default:
			// No algorithm implementation is available
			ERROR_MSG("Unknown algorithm '%i'", algorithm);

			return NULL;
	}

	// No algorithm implementation is available
	return NULL;
}

// Get the global RNG (may be an unique RNG per thread)
RNG* BotanCryptoFactory::getRNG(RNGImpl::Type name /* = RNGImpl::Default */)
{
	if (name == RNGImpl::Default)
	{
		RNG *threadRNG = NULL;

		// Lock access to the map
		MutexLocker lock(rngsMutex);

#ifdef HAVE_PTHREAD_H
		// Get thread ID
		pthread_t threadID = pthread_self();

		// Find the RNG
		std::map<pthread_t,RNG*>::iterator findIt;
		findIt=rngs.find(threadID);
		if (findIt != rngs.end())
		{
			return findIt->second;
		}

		threadRNG = new BotanRNG();
		rngs[threadID] = threadRNG;
#elif _WIN32
		// Get thread ID
		DWORD threadID = GetCurrentThreadId();

		// Find the RNG
		std::map<DWORD,RNG*>::iterator findIt;
		findIt=rngs.find(threadID);
		if (findIt != rngs.end())
		{
			return findIt->second;
		}

		threadRNG = new BotanRNG();
		rngs[threadID] = threadRNG;
#else
#error "There are no thread-specific data implementations for your operating system yet"
#endif
		return threadRNG;
	}
	else
	{
		// No RNG implementation is available
		ERROR_MSG("Unknown RNG '%i'", name);

		return NULL;
	}
}

AsymAlgo::Type BotanCryptoFactory::getGOSTType(const ByteString &param)
{/*
	// Get the CKA_PRIVATE attribute, when the attribute is not present use default false
	bool isKeyPrivate = key->getBooleanValue(CKA_PRIVATE, false);
	ByteString param;
	if (isKeyPrivate)
	{
		if(!token->decrypt(key->getByteStringValue(CKA_GOSTR3411_PARAMS), param))
			return AsymAlgo::Unknown;
	}
	else
	{
		param = key->getByteStringValue(CKA_GOSTR3411_PARAMS);
	}*/
	if(param.size() == 0)
		return AsymAlgo::Unknown;
	Botan::BER_Decoder dec(param.const_byte_str(), param.size());
	Botan::OID oid;
	Botan::OID gost_256({1,2,643,7,1,1,2,2}), gost_512({1,2,643,7,1,1,2,3});
	try {
		oid.decode_from(dec);

	}  catch (Botan::Exception except) {
		ERROR_MSG(except.what());
		return AsymAlgo::Unknown;
	}
	if(oid == gost_256)
		return AsymAlgo::GOST2012;
	else if(oid == gost_512)
		return AsymAlgo::GOST2012_512;
	else
		return AsymAlgo::GOST;
}
