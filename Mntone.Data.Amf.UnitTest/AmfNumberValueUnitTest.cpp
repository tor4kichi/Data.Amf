#include "pch.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace Mntone::Data::Amf;

TEST_CLASS( AmfNumberValueUnitTest )
{
public:
	TEST_METHOD( AmfNumberValue_CreateTest )
	{
		const auto& val = CreateDefaultNumber();
		Assert::IsTrue( val->ValueType == AmfValueType::Number );
	}

	TEST_METHOD( AmfNumberValue_GetBooleanTest )
	{
		const auto& val = CreateDefaultNumber();
		AssertHelper::ExpectInvalidOperatonException( [=]()
		{
			val->GetBoolean();
		} );
	}

	TEST_METHOD( AmfNumberValue_GetNumberTest )
	{
		const auto& val = CreateDefaultNumber();
		Assert::AreEqual( generalTestValue_, val->GetNumber() );
	}

	TEST_METHOD( AmfNumberValue_GetStringTest )
	{
		const auto& val = CreateDefaultNumber();
		AssertHelper::ExpectInvalidOperatonException( [=]()
		{
			val->GetString();
		} );
	}

	TEST_METHOD( AmfNumberValue_GetDateTest )
	{
		const auto& val = CreateDefaultNumber();
		AssertHelper::ExpectInvalidOperatonException( [=]()
		{
			val->GetDate();
		} );
	}

	TEST_METHOD( AmfNumberValue_GetByteArrayTest )
	{
		const auto& val = CreateDefaultNumber();
		AssertHelper::ExpectInvalidOperatonException( [=]()
		{
			val->GetByteArray();
		} );
	}

	TEST_METHOD( AmfNumberValue_GetVectorIntTest )
	{
		const auto& val = CreateDefaultNumber();
		AssertHelper::ExpectInvalidOperatonException( [=]()
		{
			val->GetVectorInt();
		} );
	}

	TEST_METHOD( AmfNumberValue_GetVectorUintTest )
	{
		const auto& val = CreateDefaultNumber();
		AssertHelper::ExpectInvalidOperatonException( [=]()
		{
			val->GetVectorUint();
		} );
	}

	TEST_METHOD( AmfNumberValue_GetVectorDoubleTest )
	{
		const auto& val = CreateDefaultNumber();
		AssertHelper::ExpectInvalidOperatonException( [=]()
		{
			val->GetVectorDouble();
		} );
	}

	TEST_METHOD( AmfNumberValue_GetVectorObjectTest )
	{
		const auto& val = CreateDefaultNumber();
		AssertHelper::ExpectInvalidOperatonException( [=]()
		{
			val->GetVectorObject();
		} );
	}

	TEST_METHOD( AmfNumberValue_GetObjectTest )
	{
		const auto& val = CreateDefaultNumber();
		AssertHelper::ExpectInvalidOperatonException( [=]()
		{
			val->GetObject();
		} );
	}

	TEST_METHOD( AmfNumberValue_GetArrayTest )
	{
		const auto& val = CreateDefaultNumber();
		AssertHelper::ExpectInvalidOperatonException( [=]()
		{
			val->GetArray();
		} );
	}

	TEST_METHOD( AmfNumberValue_GetDictionaryTest )
	{
		const auto& val = CreateDefaultNumber();
		AssertHelper::ExpectInvalidOperatonException( [=]()
		{
			val->GetDictionary();
		} );
	}

	TEST_METHOD( AmfNumberValue_ToStringTest )
	{
		const auto& val = CreateDefaultNumber();
		auto toStringValue = val->ToString();
		Assert::AreEqual( generalTestValue_.ToString(), toStringValue );
	}

private:
	AmfValue^ CreateDefaultNumber()
	{
		return AmfValue::CreateNumberValue( generalTestValue_ );
	}

	float64 generalTestValue_ = 4.5;
};