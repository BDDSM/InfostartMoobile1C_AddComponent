#pragma once

#include "../include/AddInDefBase.h"
#include "../include/IAndroidComponentHelper.h"
#include "../jni/jnienv.h"
#include "../include/IMemoryManager.h"

/////////////////////////////////////////////////////////////////////////////////////////////////////
//
// ������� � ������� "�������� ������� ��������� ��� ��������� ��������� 1� �� �������"
// �� ����������� INFOSTART 2018 EVENT EDUCATION https://event.infostart.ru/2018/
//
// ������ 1: ���������� �� ���������� - ��������� ��������� ������
// ������ 2: ���������� ���������� - �������� � 1� �������� ������� �� ��������� ��������� ������
//
// Copyright ����� ������ 2018
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

/* �����-������� ��� ������ ���� java ���������� ru.infostart.education*/

class LockState
{
private:

	jclass cc;
	jobject obj;

public:

	LockState();
	~LockState();

	void Initialize(IAddInDefBaseEx*, const IMemoryManager*);

	void Start() const; // ������ ����������� ��������� ����������
	void Stop() const; // ��������� ������������
};