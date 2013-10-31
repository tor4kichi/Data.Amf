#include "pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace Mntone::Data::Amf;

namespace Mntone_Data_Amf_UnitTest
{
    TEST_CLASS(Amf0UnitTest)
    {
    
	public:


		TEST_METHOD(NumberTest_Case_0_0){
			testAmf0(ref new Platform::Array<uint8>{ 0, 0, 0, 0, 0, 0, 0, 0, 0 }, [](IAmfValue^ amfValue)
			{
				Assert::AreEqual(amfValue->GetDouble(), 0.0);
			});
		}

		TEST_METHOD(NumbetTest_Case_0_5){
			testAmf0(ref new Platform::Array<uint8>{ 0, 0x3f, 0xe0, 0, 0, 0, 0, 0, 0 }, [](IAmfValue^ amfValue){
				Assert::AreEqual(amfValue->GetDouble(), 0.5);
			});
		}

		TEST_METHOD(BooleanTest_Case_True){
			testAmf0(ref new Platform::Array<uint8>{ 1, 1 }, [](IAmfValue^ amfValue){
				Assert::IsTrue(amfValue->GetBoolean());
			});
		}

		TEST_METHOD(BooleanTest_Case_False){
			testAmf0(ref new Platform::Array<uint8>{ 1, 0 }, [](IAmfValue^ amfValue){
				Assert::IsFalse(amfValue->GetBoolean());
			});
		}

		TEST_METHOD(StringTest_Case_Null){
			testAmf0(ref new Platform::Array<uint8>{ 2, 0, 0 }, [](IAmfValue^ amfValue){
				Assert::AreEqual<void*>(reinterpret_cast<void*>( amfValue->GetString()) , nullptr);
			});
		}

		TEST_METHOD(Stringtest_Case_Ascii){
			testAmf0(ref new Platform::Array<uint8>{ 2, 0, 5, 0x41, 0x53, 0x43, 0x49, 0x49 }, [](IAmfValue^ amfValue){
				Assert::AreEqual(amfValue->GetString(),ref new Platform::String( L"ASCII"));
			});
		}


		TEST_METHOD(StringTest_Case_RandomCharactors1){
			testAmf0(ref new Platform::Array<uint8>{ 2, 0, 6, 0xc2, 0xbd, 0x3a, 0x20, 0x32, 0x42 }, [](IAmfValue^ amfValue){
				Assert::AreEqual(amfValue->GetString(), ref new Platform::String(L"½: 2B"));
			});

		}

		TEST_METHOD(StringTest_Case_RandomCharactors2){
			testAmf0(ref new Platform::Array<uint8>{ 2, 0, 7, 0xe2, 0x91, 0xb4, 0x3a, 0x20, 0x33, 0x42 }, [](IAmfValue^ amfValue){
				Assert::AreEqual(amfValue->GetString(), ref new Platform::String(L"⑴: 3B"));
			});

		}


	private:

		void testAmf0(Platform::Array<uint8>^ rawData, std::function<void(IAmfValue^)> f){
			
			auto r = Amf0Parser::Parse(rawData);
			auto st = r->ToString();
			f(r);
			//checkHandler(r);
			auto createData = Amf0Sequencer::Sequenceify(r);

			Assert::IsTrue(arrayEquals(rawData, createData));


		}

		bool arrayEquals(Platform::Array<uint8>^ firstArray, Platform::Array<uint8>^ secondArray){
			if (firstArray->Length != secondArray->Length)
				return false;
			for (uint32 i = 0; i < firstArray->Length; i++)
			{
				if (!firstArray[i].Equals(secondArray[i]))
				{
					return false;
				}
			}
			return true;
		}

	
    };
}