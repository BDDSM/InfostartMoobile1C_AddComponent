﻿
#ifndef __ADDINNATIVE_H__
#define __ADDINNATIVE_H__

#include "../include/ComponentBase.h"
#include "../include/AddInDefBase.h"
#include "../include/IMemoryManager.h"
#include "LockState.h"

/////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Примеры к докладу "Создание внешних компонент для мобильной платформы 1С ОС Андроид"
// на конференции INFOSTART 2018 EVENT EDUCATION https://event.infostart.ru/2018/
//
// Пример 1: Информация об устройстве - получение серийного номера
// Пример 2: Блокировка устройства - передача в 1С внешнего события об изменении состояния экрана
//
// Copyright Игорь Кисиль 2018
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

class Infostart2018AddIn : public IComponentBase
{
public:
    enum Props
    {
			// Проект 1
			ePropSerial = 0,
			// Проект 2
			ePropScreen,
      ePropLast         // Always last
    };

    enum Methods
    {
      eMethLast = 0    // Always last
    };

		Infostart2018AddIn(void);
    virtual ~Infostart2018AddIn();
    // IInitDoneBase
    virtual bool ADDIN_API Init(void*);
    virtual bool ADDIN_API setMemManager(void* mem);
    virtual long ADDIN_API GetInfo();
    virtual void ADDIN_API Done();
    // ILanguageExtenderBase
    virtual bool ADDIN_API RegisterExtensionAs(WCHAR_T**);
    virtual long ADDIN_API GetNProps();
    virtual long ADDIN_API FindProp(const WCHAR_T* wsPropName);
    virtual const WCHAR_T* ADDIN_API GetPropName(long lPropNum, long lPropAlias);
    virtual bool ADDIN_API GetPropVal(const long lPropNum, tVariant* pvarPropVal);
    virtual bool ADDIN_API SetPropVal(const long lPropNum, tVariant* varPropVal);
    virtual bool ADDIN_API IsPropReadable(const long lPropNum);
    virtual bool ADDIN_API IsPropWritable(const long lPropNum);
    virtual long ADDIN_API GetNMethods();
    virtual long ADDIN_API FindMethod(const WCHAR_T* wsMethodName);
    virtual const WCHAR_T* ADDIN_API GetMethodName(const long lMethodNum, 
                            const long lMethodAlias);
    virtual long ADDIN_API GetNParams(const long lMethodNum);
    virtual bool ADDIN_API GetParamDefValue(const long lMethodNum, const long lParamNum,
                            tVariant *pvarParamDefValue);   
    virtual bool ADDIN_API HasRetVal(const long lMethodNum);
    virtual bool ADDIN_API CallAsProc(const long lMethodNum,
                    tVariant* paParams, const long lSizeArray);
    virtual bool ADDIN_API CallAsFunc(const long lMethodNum,
                tVariant* pvarRetValue, tVariant* paParams, const long lSizeArray);
    // ILocaleBase
    virtual void ADDIN_API SetLocale(const WCHAR_T* loc);

private:
    long findName(const wchar_t* names[], const wchar_t* name, const uint32_t size) const;
    void addError(uint32_t wcode, const wchar_t* source, 
                    const wchar_t* descriptor, long code);

		bool isNumericParameter(tVariant*);
		long numericValue(tVariant*);

		void ToV8String(const wchar_t* wstr, tVariant*);
		WCHAR_T* ToV8StringJni(jstring jstr, int* lSize);

    IAddInDefBaseEx    *m_iConnect;
    IMemoryManager     *m_iMemory;

		// Проект 2

		bool isScreenOn; // хранит текущее состояние блокировки
		LockState m_devState{};

		// Проект 2 end
};

#endif
