#ifndef QTADSOPERATE_H
#define QTADSOPERATE_H

#define BOOL  bool

#include <QObject>
#include "TcAdsDef.h"
#include "TcAdsAPI.h"
#include<QVector>

struct _AdsStruct
{
	qint16 nData;
	char cByte;
};

class QtAdsOperate : public QObject
{
	Q_OBJECT
public:
	explicit QtAdsOperate(QObject *parent = 0);
	AmsAddr  m_addr;


public:
	unsigned int m_hBool1;
	unsigned int m_hBool2;
	unsigned int m_hBool3;
	unsigned int m_hBool4;
	unsigned int m_hBool5;
	unsigned int m_hBool6;
	unsigned int m_hBool7;
	unsigned int m_hBool8;
	unsigned int m_hBool9;
	unsigned int m_hBool10;
	unsigned int m_hBool11;
	unsigned int m_hBool12;
	unsigned int m_hBool13;
	unsigned int m_hBool14;
	unsigned int m_hBool15;
	unsigned int m_hBool16;
	unsigned int m_hBool17;
	unsigned int m_hBool18;
	unsigned int m_hBool19;
    unsigned int m_hBool20;
	unsigned int m_hBool21;
	unsigned int m_hBool22;
	unsigned int m_hBool23;
	unsigned int m_hBool24;
	unsigned int m_hBool25;
	unsigned int m_hBool26;
	unsigned int m_hBool27;
	unsigned int m_hBool28;
	unsigned int m_hBool29;
	unsigned int m_hBool30;
	unsigned int m_hBool31;
	unsigned int m_hBool32;
	unsigned int m_hBool33;
	unsigned int m_hBool34;
	unsigned int m_hBool35;
	unsigned int m_hBool36;
	unsigned int m_hBool37;
	unsigned int m_hBool38;
	unsigned int m_hBool40;
	unsigned int m_hBool41;
	unsigned int m_hBool42;
	unsigned int m_hBool43;
	unsigned int m_hBool44;

	unsigned int m_hByte;
	unsigned int m_hByte1;

	unsigned int m_hInt;
	unsigned int m_hInt1;
	unsigned int m_hInt2;
	unsigned int m_hInt3;
	unsigned int m_hInt4;
	unsigned int m_hInt5;
	unsigned int m_hInt7;

	unsigned int m_hFloat1;
	unsigned int m_hFloat2;
	unsigned int m_hFloat3;
	unsigned int m_hFloat4;
	unsigned int m_hFloat5;
	unsigned int m_hFloat6;
	//unsigned int m_hFloat7;
	//unsigned int m_hFloat8;
	unsigned int m_hString1;
	unsigned int m_hString2;
	unsigned int m_hString3;
	//unsigned int m_hString4;
	//unsigned int m_hString5;
	//unsigned int m_hString6;
	//unsigned int m_hString7;
	unsigned int m_hArray;
	unsigned int m_hStruct;
signals:

	public slots :
		bool readBool();
	char readByte();
	bool readBool(unsigned int m_hBool);
	qint16 readInt(unsigned int m_hInt);
	float readFloat(unsigned int m_hFloat);	
	QString readString(unsigned int m_hString);	
	QVector<int> readArray();
	QByteArray readStruct();

	void writeBool(unsigned int m_hBool, bool bValue);
	void writeByte(unsigned int m_hByte, char cValue);
	void writeInt(unsigned int m_hInt, qint16 cValue);
	void writeFloat(unsigned int m_hFloat, float bfloat);
	void writeString(unsigned int m_hString, QString str);		
	void writeArray(QVector<int> nVec);
	void writeStruct(QByteArray str);

};

#endif // QTADSOPERATE_H

