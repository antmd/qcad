

    // ***** AUTOGENERATED CODE, DO NOT EDIT *****
    
            // ***** This class is not copyable.
        
        #ifndef RECMALINETYPECOMBO_H
        #define RECMALINETYPECOMBO_H

        #include <QScriptEngine>
        #include <QScriptValue>
        #include <QScriptContextInfo>
        #include <QDebug>

        
                #include "RLinetypeCombo.h"
            

        /**
         * \ingroup scripting_ecmaapi
         */
        class REcmaLinetypeCombo {

        public:
      static  void init(QScriptEngine& engine, QScriptValue* proto 
    =NULL
    ) 
    ;static  QScriptValue create(QScriptContext* context, QScriptEngine* engine) 
    ;

    // conversion functions for base classes:
    static  QScriptValue getQComboBox(QScriptContext *context,
            QScriptEngine *engine)
        ;

    // returns class name:
    static  QScriptValue getClassName(QScriptContext *context, QScriptEngine *engine) 
        ;

    // returns all base classes (in case of multiple inheritance):
    static  QScriptValue getBaseClasses(QScriptContext *context, QScriptEngine *engine) 
        ;

    // properties:
    

    // public methods:
    static  QScriptValue
        getLinetype
        (QScriptContext* context, QScriptEngine* engine) 
        ;static  QScriptValue
        setLinetype
        (QScriptContext* context, QScriptEngine* engine) 
        ;static  QScriptValue
        init
        (QScriptContext* context, QScriptEngine* engine) 
        ;static  QScriptValue
        getOnlyFixed
        (QScriptContext* context, QScriptEngine* engine) 
        ;static  QScriptValue
        setOnlyFixed
        (QScriptContext* context, QScriptEngine* engine) 
        ;static  QScriptValue
        linetypeChanged
        (QScriptContext* context, QScriptEngine* engine) 
        ;static  QScriptValue toString
    (QScriptContext *context, QScriptEngine *engine)
    ;static  QScriptValue destroy(QScriptContext *context, QScriptEngine *engine)
    ;static RLinetypeCombo* getSelf(const QString& fName, QScriptContext* context)
    ;static RLinetypeCombo* getSelfShell(const QString& fName, QScriptContext* context)
    ;static  void fromScriptValue(const QScriptValue& value,
        RLinetypeCombo*
        &out) {
            QObject* o = value.toQObject();
            out = qobject_cast<
            RLinetypeCombo*>(o);
        }
    static  QScriptValue toScriptValue(QScriptEngine *engine,
        RLinetypeCombo*
        const &in){
            QScriptValue s = engine->newQObject(in, QScriptEngine::QtOwnership,
            QScriptEngine::PreferExistingWrapperObject);
            /*
            if(s.isNull()){
               REcmaHelper::throwError("This object is null.", engine->currentContext());
            }
            */
            return s;
        }
    };
    #endif
    