#include "TransformComponent.h"
#include <Utilities/Math/Vector.h>

float StringToFloat( String^ str )
{
	auto x = str->Replace( ' ', '0' );
	if ( x[x->Length - 1] == Convert::ToChar( "." ) )
		x = x->Replace( ".", ".0" );
	return Convert::ToSingle( x );
}
String^ FloatToString( float v )
{
	if ( v < 0.0f )
		return v.ToString( "#000.000" );
	else
		return v.ToString( "0000.000" );
}
void Editor::TransformComponent::Create()
{
	engine->engine->get_entity_components().transform_component->create( entity );
	posX->Text = FloatToString( 0.0 );
	posY->Text = FloatToString( 0.0 );
	posZ->Text = FloatToString( 0.0 );
	
	rotX->Text = FloatToString( 0.0 );
	rotY->Text = FloatToString( 0.0 );
	rotZ->Text = FloatToString( 0.0 );

	scaleX->Text = FloatToString( 1.0 );
	scaleY->Text = FloatToString( 1.0 );
	scaleZ->Text = FloatToString( 1.0 );
}
System::Void Editor::TransformComponent::posChanged( System::Object^ sender, System::EventArgs^ e )
{
	Utilities::Math::Vector pos;
	pos.x = StringToFloat( posX->Text );
	pos.y = StringToFloat( posY->Text );
	pos.z = StringToFloat( posZ->Text );
	engine->engine->get_entity_components().transform_component->set_position( entity, pos );
}

System::Void Editor::TransformComponent::rotChanged( System::Object^ sender, System::EventArgs^ e )
{
	Utilities::Math::Vector rot;
	rot.x = StringToFloat( rotX->Text );
	rot.y = StringToFloat( rotY->Text );
	rot.z = StringToFloat( rotZ->Text );
	engine->engine->get_entity_components().transform_component->set_rotation( entity, rot );
}

System::Void Editor::TransformComponent::scaleChanged( System::Object^ sender, System::EventArgs^ e )
{
	Utilities::Math::Vector scale;
	scale.x = StringToFloat( scaleX->Text );
	scale.y = StringToFloat( scaleY->Text );
	scale.z = StringToFloat( scaleZ->Text );
	engine->engine->get_entity_components().transform_component->set_scale( entity, scale );
}
