// ***** AUTOGENERATED CODE, DO NOT EDIT *****
            // ***** This class is not copyable.
        
        #ifndef RECMAFILEIMPORTERREGISTRY_H
        #define RECMAFILEIMPORTERREGISTRY_H

        #include "ecmaapi_global.h"

        #include <QScriptEngine>
        #include <QScriptValue>
        #include <QScriptContextInfo>
        #include <QDebug>

        
                #include "RFileImporterRegistry.h"
            

        /**
         * \ingroup scripting_ecmaapi
         */
        class
        
        QCADECMAAPI_EXPORT
        REcmaFileImporterRegistry {

        public:
      static  void initEcma(QScriptEngine& engine, QScriptValue* proto 
    =NULL
    ) 
    ;static  QScriptValue create(QScriptContext* context, QScriptEngine* engine) 
    ;

    // conversion functions for base classes:
    

    // returns class name:
    static  QScriptValue getClassName(QScriptContext *context, QScriptEngine *engine) 
        ;

    // returns all base classes (in case of multiple inheritance):
    static  QScriptValue getBaseClasses(QScriptContext *context, QScriptEngine *engine) 
        ;

    // properties:
    

    // public methods:
    static  QScriptValue
        registerFileImporter
        (QScriptContext* context, QScriptEngine* engine) 
        ;static  QScriptValue
        unregisterFileImporter
        (QScriptContext* context, QScriptEngine* engine) 
        ;static  QScriptValue
        getFileImporter
        (QScriptContext* context, QScriptEngine* engine) 
        ;static  QScriptValue
        getFilterStrings
        (QScriptContext* context, QScriptEngine* engine) 
        ;static  QScriptValue
        hasFileImporter
        (QScriptContext* context, QScriptEngine* engine) 
        ;static  QScriptValue
        getFilterExtensions
        (QScriptContext* context, QScriptEngine* engine) 
        ;static  QScriptValue
        getFilterExtensionPatterns
        (QScriptContext* context, QScriptEngine* engine) 
        ;static  QScriptValue toString
    (QScriptContext *context, QScriptEngine *engine)
    ;static  QScriptValue destroy(QScriptContext *context, QScriptEngine *engine)
    ;static RFileImporterRegistry* getSelf(const QString& fName, QScriptContext* context)
    ;static RFileImporterRegistry* getSelfShell(const QString& fName, QScriptContext* context)
    ;};
    #endif
    