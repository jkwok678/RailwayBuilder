#include "element.h"


//Element class implementation.


Element::Element()
{

}

Element::Element(int currentX, int currentY)
{
	locationX = currentX;
	locationY = currentY;
}

int Element::getLocationX() const
{
	return locationX;
}

void Element::setLocationX(int newLocationX)
{
	locationX = newLocationX;
}

int Element::getLocationY() const
{
	return locationY;
}

void Element::setLocationY(int newLocationY)
{
	locationY = newLocationY;
}


//Text class implementation.


Text::Text(int newLocationX, int newLocationY, QString newReadableText, QFont newFont)
{
	locationX = newLocationX;
	locationY = newLocationY;
	readableText = newReadableText;
	editableX = locationX + fontSize;
	editableY = locationY + fontSize;
	font = newFont;
}

int Text::getEditableX() const
{
	return editableX;
}

void Text::setEditableX(int newEditableX)
{
	editableX = newEditableX;
}

int Text::getEditableY() const
{
	return editableY;
}

void Text::setEditableY(int newEditableY)
{
	editableY = newEditableY;
}

int Text::getFontSize() const
{
	return fontSize;
}

void Text::setFontSize(int newFontSize)
{
	fontSize = newFontSize;
}

QString Text::getReadableText() const
{
	return readableText;
}

void Text::setReadableText(const QString& newReadableText)
{
	readableText = newReadableText;
}

QFont Text::getFont() const
{
	return font;
}

void Text::setFont(const QFont newFont)
{
	font = newFont;
}

QString Text::toQString()
{
	QString textQString = "Text";
	textQString.append(",");
	textQString.append(QString::number(locationX));
	textQString.append(",");
	textQString.append(QString::number(locationY));
	textQString.append(",");
	textQString.append(font.toString());
	return textQString;
}


//NamedElement class implementation.


NamedElement::NamedElement()
{

}

bool NamedElement::getNamed() const
{
	return named;
}

void NamedElement::setNamed(bool newNamed)
{
	named = newNamed;
}

std::shared_ptr<Text> NamedElement::getText()
{
	return text;
}

void NamedElement::setText(std::shared_ptr<Text> &newText)
{
	text = newText;
}

QString NamedElement::toQString()
{
	QString namedElementQString = "NamedElement";
	namedElementQString.append(",");
	namedElementQString.append(QString::number(locationX));
	namedElementQString.append(",");
	namedElementQString.append(QString::number(locationY));
	if(text != nullptr)
	{
		namedElementQString.append(",");
		namedElementQString.append(text->toQString());
	}
	return namedElementQString;

}


//NamedLocation class implementation.


NamedLocation::NamedLocation(int newLocationX, int newLocationY)
{
	locationX = newLocationX;
	locationY = newLocationY;
	named = false;
	text = nullptr;


}

QString NamedLocation::toQString()
{
	QString namedLocationQString = "NamedLocation";
	namedLocationQString.append(",");
	namedLocationQString.append(QString::number(locationX));
	namedLocationQString.append(",");
	namedLocationQString.append(QString::number(locationY));
	if(text != nullptr)
	{
		namedLocationQString.append(",");
		namedLocationQString.append(text->toQString());
	}
	return namedLocationQString;
}


//Concourse class implementation.


Concourse::Concourse(int newLocationX, int newLocationY)
{
	locationX = newLocationX;
	locationY = newLocationY;
	named = false;
	text = nullptr;

}

QString Concourse::toQString()
{
	QString namedElementQString = "Concourse";
	namedElementQString.append(",");
	namedElementQString.append(QString::number(locationX));
	namedElementQString.append(",");
	namedElementQString.append(QString::number(locationY));
	if(text != nullptr)
	{
		namedElementQString.append(",");
		namedElementQString.append(text->toQString());
	}
	return namedElementQString;
}

//Parapet class implementation.

Parapet::Parapet(ParapetType newParapetType, int newLocationX, int newLocationY)
{
	parapetType = newParapetType;
	locationX = newLocationX;
	locationY = newLocationY;
}

ParapetType Parapet::getParapetType() const
{
	return parapetType;
}

void Parapet::setParapetType(const ParapetType &newParapetType)
{
	parapetType = newParapetType;
}

QString Parapet::parapetTypeToQString()
{
	QString parapetTypeQString;
	switch (parapetType)
	{
	case ParapetType::PARAPET1:
		parapetTypeQString = "parapet_1";
		break;
	case ParapetType::PARAPET2:
		parapetTypeQString = "parapet_2";
		break;
	case ParapetType::PARAPET3:
		parapetTypeQString = "parapet_3";
		break;
	case ParapetType::PARAPET4:
		parapetTypeQString = "parapet_4";
		break;
	case ParapetType::PARAPET5:
		parapetTypeQString = "parapet_5";
		break;
	case ParapetType::PARAPET6:
		parapetTypeQString = "parapet_6";
		break;
	case ParapetType::PARAPET7:
		parapetTypeQString = "parapet_7";
		break;
	case ParapetType::PARAPET8:
		parapetTypeQString = "parapet_8";
		break;
	case ParapetType::PARAPET9:
		parapetTypeQString = "parapet_9";
		break;
	case ParapetType::PARAPET10:
		parapetTypeQString = "parapet_10";
		break;
	case ParapetType::PARAPET11:
		parapetTypeQString = "parapet_11";
		break;
	case ParapetType::PARAPET12:
		parapetTypeQString = "parapet_12";
		break;
	case ParapetType::PARAPET13:
		parapetTypeQString = "parapet_13";
		break;
	case ParapetType::PARAPET14:
		parapetTypeQString = "parapet_14";
		break;
	case ParapetType::PARAPET15:
		parapetTypeQString = "parapet_15";
		break;
	case ParapetType::PARAPET16:
		parapetTypeQString = "parapet_16";
		break;
	case ParapetType::PARAPET17:
		parapetTypeQString = "parapet_17";
		break;
	case ParapetType::PARAPET18:
		parapetTypeQString = "parapet_18";
		break;
	case ParapetType::PARAPET19:
		parapetTypeQString = "parapet_19";
		break;
	case ParapetType::PARAPET20:
		parapetTypeQString = "parapet_20";
		break;
	case ParapetType::PARAPET21:
		parapetTypeQString = "parapet_21";
		break;
	case ParapetType::PARAPET22:
		parapetTypeQString = "parapet_22";
		break;
	case ParapetType::PARAPET23:
		parapetTypeQString = "parapet_23";
		break;
	case ParapetType::PARAPET24:
		parapetTypeQString = "parapet_24";
		break;
	case ParapetType::PARAPET25:
		parapetTypeQString = "parapet_25";
		break;
	case ParapetType::PARAPET26:
		parapetTypeQString = "parapet_26";
		break;
	case ParapetType::PARAPET27:
		parapetTypeQString = "parapet_27";
		break;
	case ParapetType::PARAPET28:
		parapetTypeQString = "parapet_28";
		break;
	}
	return parapetTypeQString;
}

QString Parapet::toQString()
{
	QString parapetQString = "Parapet";
	parapetQString.append(",");
	parapetQString.append(parapetTypeToQString());
	parapetQString.append(",");
	parapetQString.append(QString::number(locationX));
	parapetQString.append(",");
	parapetQString.append(QString::number(locationY));
	return parapetQString;
}
