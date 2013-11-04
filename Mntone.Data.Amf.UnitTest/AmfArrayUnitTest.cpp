#include "pch.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace Mntone::Data::Amf;

TEST_CLASS( AmfArrayUnitTest )
{
public:
	TEST_METHOD( AmfArray_ConstractorTest )
	{
		const auto& ary = ref new AmfArray();
		Assert::IsTrue( ary->ValueType == AmfValueType::Array );
		Assert::AreEqual<uint32>( 0, ary->Size );
	}

	TEST_METHOD( AmfArray_CreateStrictArrayTest_Member )
	{
		const auto& ary = ref new AmfArray();
		Assert::IsTrue( ary->ValueType == AmfValueType::Array );
		Assert::AreEqual<uint32>( 0, ary->Size );
	}

	TEST_METHOD( AmfArray_AppendAndGetFirstTest )
	{
		const auto& ary = ref new AmfArray();
		ary->Append( AmfValue::CreateBooleanValue( false ) );
		Assert::AreEqual<uint32>( 1, ary->Size );

		const auto& firstValue = ary->GetAt( 0 );
		Assert::IsTrue( firstValue->ValueType == AmfValueType::Boolean );
		Assert::IsFalse( firstValue->GetBoolean() );
	}

	TEST_METHOD( AmfArray_NoneItemTest_OutOfRangeException )
	{
		const auto& ary = ref new AmfArray();

		Assert::ExpectException<Platform::OutOfBoundsException^>( [ary]
		{
			ary->GetAt( 0 );
		} );
	}

	TEST_METHOD( AmfArray_GetBooleanTest_FailureException )
	{
		FailureExceptionTest( []( AmfArray^ ary )
		{
			ary->GetBoolean();
		} );
	}

	TEST_METHOD( AmfArray_GetDoubleTest_FailureException )
	{
		FailureExceptionTest( []( AmfArray^ ary )
		{
			ary->GetDouble();
		} );
	}

	TEST_METHOD( AmfArray_GetIntegerTest_FailureException )
	{
		FailureExceptionTest( []( AmfArray^ ary )
		{
			ary->GetInteger();
		} );
	}

	TEST_METHOD( AmfArray_GetStringTest_FailureException )
	{
		FailureExceptionTest( []( AmfArray^ ary )
		{
			ary->GetString();
		} );
	}

	TEST_METHOD( AmfArray_GetDateTest_FailureException )
	{
		FailureExceptionTest( []( AmfArray^ ary )
		{
			ary->GetDate();
		} );
	}

	TEST_METHOD( AmfArray_GetByteArrayTest_FailureException )
	{
		FailureExceptionTest( []( AmfArray^ ary )
		{
			ary->GetByteArray();
		} );
	}

	TEST_METHOD( AmfArray_GetVectorIntTest_FailureException )
	{
		FailureExceptionTest( []( AmfArray^ ary )
		{
			ary->GetVectorInt();
		} );
	}

	TEST_METHOD( AmfArray_GetVectorUintTest_FailureException )
	{
		FailureExceptionTest( []( AmfArray^ ary )
		{
			ary->GetVectorUint();
		} );
	}

	TEST_METHOD( AmfArray_GetVectorDouble_FailureException )
	{
		FailureExceptionTest( []( AmfArray^ ary )
		{
			ary->GetDouble();
		} );
	}

	TEST_METHOD( AmfArray_ToStringTest_NoneItem )
	{
		const auto& ary = ref new AmfArray();
		Assert::AreEqual( L"[]", ary->ToString() );
	}

	TEST_METHOD( AmfArray_ToStringTest_SomeItems )
	{
		const auto& ary = ref new AmfArray();
		ary->Append( AmfValue::CreateBooleanValue( true ) );
		ary->Append( AmfValue::CreateIntegerValue( 50 ) );
		Assert::AreEqual( L"[true, 50, ]", ary->ToString() );
	}

	TEST_METHOD( AmfArray_ParseTest_Default )
	{
		const auto& ary = AmfArray::Parse( ref new Platform::Array<uint8>{ 0 } );
		Assert::IsTrue( ary->ValueType == AmfValueType::Undefined );
	}

	TEST_METHOD( AmfArray_ParseTest_Amf0 )
	{
		const auto& ary = AmfArray::Parse( ref new Platform::Array<uint8>{ 0, 0, 0, 0, 0, 0, 0, 0, 0 }, AmfEncodingType::Amf0 );
		Assert::IsTrue( ary->ValueType == AmfValueType::Double );
		Assert::AreEqual( 0.0, ary->GetDouble() );
	}

	TEST_METHOD( AmfArray_ParseTest_Amf3 )
	{
		const auto& ary = AmfArray::Parse( ref new Platform::Array<uint8>{ 0 }, AmfEncodingType::Amf3 );
		Assert::IsTrue( ary->ValueType == AmfValueType::Undefined );
	}

	TEST_METHOD( AmfArray_TryParseTest_Default )
	{
		AmfArray^ ary;
		Assert::IsTrue( AmfArray::TryParse( ref new Platform::Array<uint8>{ 0 }, &ary ) );
		Assert::IsTrue( ary->ValueType == AmfValueType::Undefined );
	}

	TEST_METHOD( AmfArray_TryParseTest_Amf0 )
	{
		AmfArray^ ary;
		Assert::IsTrue( AmfArray::TryParse( ref new Platform::Array<uint8>{ 0, 0, 0, 0, 0, 0, 0, 0, 0 }, AmfEncodingType::Amf0, &ary ) );
		Assert::IsTrue( ary->ValueType == AmfValueType::Double );
		Assert::AreEqual( 0.0, ary->GetDouble() );
	}

	TEST_METHOD( AmfArray_TryParseTest_Amf3 )
	{
		AmfArray^ ary;
		Assert::IsTrue( AmfArray::TryParse( ref new Platform::Array<uint8>{ 0 }, AmfEncodingType::Amf3, &ary ) );
		Assert::IsTrue( ary->ValueType == AmfValueType::Undefined );
	}

private:
	void FailureExceptionTest( std::function<void( AmfArray^ )> testHandler )
	{
		const auto& ary = ref new AmfArray();
		Assert::ExpectException<Platform::FailureException^>( [ary, testHandler]
		{
			testHandler( ary );
		} );
	}
};