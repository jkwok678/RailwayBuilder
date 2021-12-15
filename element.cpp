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
	QString locationXQString = QString::number(locationX);
	textQString.append(locationXQString);
	QString locationYQString = QString::number(locationY);
	textQString.append(locationYQString);
	QString fontQString = font.toString();
	textQString.append(fontQString);
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
	QString locationXQString = QString::number(locationX);
	namedElementQString.append(locationXQString);
	QString locationYQString = QString::number(locationY);
	namedElementQString.append(locationYQString);
	if(text != nullptr)
	{

		QString textQString = text->toQString();
		namedElementQString.append(textQString);
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
	QString locationXQString = QString::number(locationX);
	namedLocationQString.append(locationXQString);
	QString locationYQString = QString::number(locationY);
	namedLocationQString.append(locationYQString);
	if(text != nullptr)
	{

		QString textQString = text->toQString();
		namedLocationQString.append(textQString);
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
	QString locationXQString = QString::number(locationX);
	namedElementQString.append(locationXQString);
	QString locationYQString = QString::number(locationY);
	namedElementQString.append(locationYQString);
	if(text != nullptr)
	{

		QString textQString = text->toQString();
		namedElementQString.append(textQString);
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
		parapetTypeQString = "p1";
		break;
	case ParapetType::PARAPET2:
		parapetTypeQString = "p2";
		break;
	case ParapetType::PARAPET3:
		parapetTypeQString = "p3";
		break;
	case ParapetType::PARAPET4:
		parapetTypeQString = "p4";
		break;
	case ParapetType::PARAPET5:
		parapetTypeQString = "p5";
		break;
	case ParapetType::PARAPET6:
		parapetTypeQString = "p6";
		break;
	case ParapetType::PARAPET7:
		parapetTypeQString = "p7";
		break;
	case ParapetType::PARAPET8:
		parapetTypeQString = "p8";
		break;
	case ParapetType::PARAPET9:
		parapetTypeQString = "p9";
		break;
	case ParapetType::PARAPET10:
		parapetTypeQString = "p10";
		break;
	case ParapetType::PARAPET11:
		parapetTypeQString = "p11";
		break;
	case ParapetType::PARAPET12:
		parapetTypeQString = "p12";
		break;
	case ParapetType::PARAPET13:
		parapetTypeQString = "p13";
		break;
	case ParapetType::PARAPET14:
		parapetTypeQString = "p14";
		break;
	case ParapetType::PARAPET15:
		parapetTypeQString = "p15";
		break;
	case ParapetType::PARAPET16:
		parapetTypeQString = "p16";
		break;
	case ParapetType::PARAPET17:
		parapetTypeQString = "p17";
		break;
	case ParapetType::PARAPET18:
		parapetTypeQString = "p18";
		break;
	case ParapetType::PARAPET19:
		parapetTypeQString = "p19";
		break;
	case ParapetType::PARAPET20:
		parapetTypeQString = "p20";
		break;
	case ParapetType::PARAPET21:
		parapetTypeQString = "p21";
		break;
	case ParapetType::PARAPET22:
		parapetTypeQString = "p22";
		break;
	case ParapetType::PARAPET23:
		parapetTypeQString = "p23";
		break;
	case ParapetType::PARAPET24:
		parapetTypeQString = "p24";
		break;
	case ParapetType::PARAPET25:
		parapetTypeQString = "p25";
		break;
	case ParapetType::PARAPET26:
		parapetTypeQString = "p26";
		break;
	case ParapetType::PARAPET27:
		parapetTypeQString = "p27";
		break;
	case ParapetType::PARAPET28:
		parapetTypeQString = "p28";
		break;
	}
	return parapetTypeQString;
}

QString Parapet::toQString()
{
	QString parapetQString = "Parapet";
	parapetQString.append(",");
	QString parapetTypeQString = parapetTypeToQString();
	parapetQString.append(parapetTypeQString);
	QString locationXQString = QString::number(locationX);
	parapetQString.append(locationXQString);
	QString locationYQString = QString::number(locationY);
	parapetQString.append(locationYQString);
	return parapetQString;
}
