// ***** AUTOGENERATED CODE, DO NOT EDIT *****
            // ***** This class is not copyable.
        
        #include "REcmaFileImporterAdapter.h"
        #include "RMetaTypes.h"
        #include "../REcmaHelper.h"

        // forwards declarations mapped to includes
        
                #include "RDocument.h"
            
                #include "RMessageHandler.h"
            
                #include "RProgressHandler.h"
            
            
        // includes for base ecma wrapper classes
        
                  #include "REcmaFileImporter.h"
                 void REcmaFileImporterAdapter::init(QScriptEngine& engine, QScriptValue* proto 
    
    ) 
    
    {

    bool protoCreated = false;
    if(proto == NULL){
        proto = new QScriptValue(engine.newVariant(qVariantFromValue(
                (RFileImporterAdapter*) 0)));
        protoCreated = true;
    }

    
        // primary base class RFileImporter:
        
            QScriptValue dpt = engine.defaultPrototype(
                qMetaTypeId<RFileImporter*>());

            if (dpt.isValid()) {
                proto->setPrototype(dpt);
            }
          
        /*
        
        */
    

    QScriptValue fun;

    // toString:
    REcmaHelper::registerFunction(&engine, proto, toString, "toString");
    

    // destroy:
    REcmaHelper::registerFunction(&engine, proto, destroy, "destroy");
    
        // conversion for base class RFileImporter
        REcmaHelper::registerFunction(&engine, proto, getRFileImporter, "getRFileImporter");
        
        // conversion for base class RImporter
        REcmaHelper::registerFunction(&engine, proto, getRImporter, "getRImporter");
        

    // get class name
    REcmaHelper::registerFunction(&engine, proto, getClassName, "getClassName");
    

    // conversion to all base classes (multiple inheritance):
    REcmaHelper::registerFunction(&engine, proto, getBaseClasses, "getBaseClasses");
    

    // properties:
    

    // methods:
    
            REcmaHelper::registerFunction(&engine, proto, importFile, "importFile");
            
        engine.setDefaultPrototype(
            qMetaTypeId<RFileImporterAdapter*>(), *proto);

        
    

    QScriptValue ctor = engine.newFunction(create, *proto, 2);
    
    // static methods:
    

    // static properties:
    

    // enum values:
    

    // enum conversions:
    
        
    // init class:
    engine.globalObject().setProperty("RFileImporterAdapter",
    ctor, QScriptValue::SkipInEnumeration);
    
    if( protoCreated ){
       delete proto;
    }
    
    }
     QScriptValue REcmaFileImporterAdapter::create(QScriptContext* context, QScriptEngine* engine) 
    
    {
    if (context->thisObject().strictlyEquals(
       engine->globalObject())) {
       return REcmaHelper::throwError(
       QString::fromLatin1("RFileImporterAdapter(): Did you forget to construct with 'new'?"),
           context);
    }

    QScriptValue result;
        
            // generate constructor variants:
            
    if( context->argumentCount() ==
        0
    ){
    // prepare arguments:
    
    // end of arguments

    // call C++ constructor:
    
            // non-copyable class:
            REcmaShellFileImporterAdapter
                    * cppResult =
                    new
                    REcmaShellFileImporterAdapter
                    ();
                
                    // TODO: triggers: Warning: QScriptEngine::newVariant(): changing class of non-QScriptObject not supported:
                    result = engine->newVariant(context->thisObject(), qVariantFromValue(cppResult));
                
        cppResult->__qtscript_self = result;
    
    } else 

    if( context->argumentCount() ==
        1
                && (
                
                        context->argument(
                        0
                        ).isVariant()
                        ||
                    
                        context->argument(
                        0
                        ).isQObject()
                        ||
                    
                        context->argument(
                        0
                        ).isNull()
                ) /* type: RDocument */
            
    ){
    // prepare arguments:
    
                    // argument is reference
                    RDocument*
                    ap0 =
                    qscriptvalue_cast<
                    RDocument*
                        >(
                        context->argument(
                        0
                        )
                    );
                    if( ap0 == NULL ){
                           return REcmaHelper::throwError("RFileImporterAdapter: Argument 0 is not of type RDocument*.",
                               context);                    
                    }
                    RDocument& a0 = *ap0;
                
    // end of arguments

    // call C++ constructor:
    
            // non-copyable class:
            REcmaShellFileImporterAdapter
                    * cppResult =
                    new
                    REcmaShellFileImporterAdapter
                    (
                    a0
                    );
                
                    // TODO: triggers: Warning: QScriptEngine::newVariant(): changing class of non-QScriptObject not supported:
                    result = engine->newVariant(context->thisObject(), qVariantFromValue(cppResult));
                
        cppResult->__qtscript_self = result;
    
    } else 

    if( context->argumentCount() ==
        2
                && (
                
                        context->argument(
                        0
                        ).isVariant()
                        ||
                    
                        context->argument(
                        0
                        ).isQObject()
                        ||
                    
                        context->argument(
                        0
                        ).isNull()
                ) /* type: RDocument */
            
                && (
                
                        context->argument(
                        1
                        ).isVariant()
                        ||
                    
                        context->argument(
                        1
                        ).isQObject()
                        ||
                    
                        context->argument(
                        1
                        ).isNull()
                ) /* type: RMessageHandler * */
            
    ){
    // prepare arguments:
    
                    // argument is reference
                    RDocument*
                    ap0 =
                    qscriptvalue_cast<
                    RDocument*
                        >(
                        context->argument(
                        0
                        )
                    );
                    if( ap0 == NULL ){
                           return REcmaHelper::throwError("RFileImporterAdapter: Argument 0 is not of type RDocument*.",
                               context);                    
                    }
                    RDocument& a0 = *ap0;
                
                    // argument is pointer
                    RMessageHandler * a1 = NULL;

                    a1 = 
                        REcmaHelper::scriptValueTo<RMessageHandler >(
                            context->argument(1)
                        );
                    
                    if (a1==NULL && 
                        !context->argument(1).isNull()) {
                        return REcmaHelper::throwError("RFileImporterAdapter: Argument 1 is not of type RMessageHandler *RMessageHandler *.", context);                    
                    }
                
    // end of arguments

    // call C++ constructor:
    
            // non-copyable class:
            REcmaShellFileImporterAdapter
                    * cppResult =
                    new
                    REcmaShellFileImporterAdapter
                    (
                    a0
        ,
    a1
                    );
                
                    // TODO: triggers: Warning: QScriptEngine::newVariant(): changing class of non-QScriptObject not supported:
                    result = engine->newVariant(context->thisObject(), qVariantFromValue(cppResult));
                
        cppResult->__qtscript_self = result;
    
    } else 

    if( context->argumentCount() ==
        3
                && (
                
                        context->argument(
                        0
                        ).isVariant()
                        ||
                    
                        context->argument(
                        0
                        ).isQObject()
                        ||
                    
                        context->argument(
                        0
                        ).isNull()
                ) /* type: RDocument */
            
                && (
                
                        context->argument(
                        1
                        ).isVariant()
                        ||
                    
                        context->argument(
                        1
                        ).isQObject()
                        ||
                    
                        context->argument(
                        1
                        ).isNull()
                ) /* type: RMessageHandler * */
            
                && (
                
                        context->argument(
                        2
                        ).isVariant()
                        ||
                    
                        context->argument(
                        2
                        ).isQObject()
                        ||
                    
                        context->argument(
                        2
                        ).isNull()
                ) /* type: RProgressHandler * */
            
    ){
    // prepare arguments:
    
                    // argument is reference
                    RDocument*
                    ap0 =
                    qscriptvalue_cast<
                    RDocument*
                        >(
                        context->argument(
                        0
                        )
                    );
                    if( ap0 == NULL ){
                           return REcmaHelper::throwError("RFileImporterAdapter: Argument 0 is not of type RDocument*.",
                               context);                    
                    }
                    RDocument& a0 = *ap0;
                
                    // argument is pointer
                    RMessageHandler * a1 = NULL;

                    a1 = 
                        REcmaHelper::scriptValueTo<RMessageHandler >(
                            context->argument(1)
                        );
                    
                    if (a1==NULL && 
                        !context->argument(1).isNull()) {
                        return REcmaHelper::throwError("RFileImporterAdapter: Argument 1 is not of type RMessageHandler *RMessageHandler *.", context);                    
                    }
                
                    // argument is pointer
                    RProgressHandler * a2 = NULL;

                    a2 = 
                        REcmaHelper::scriptValueTo<RProgressHandler >(
                            context->argument(2)
                        );
                    
                    if (a2==NULL && 
                        !context->argument(2).isNull()) {
                        return REcmaHelper::throwError("RFileImporterAdapter: Argument 2 is not of type RProgressHandler *RProgressHandler *.", context);                    
                    }
                
    // end of arguments

    // call C++ constructor:
    
            // non-copyable class:
            REcmaShellFileImporterAdapter
                    * cppResult =
                    new
                    REcmaShellFileImporterAdapter
                    (
                    a0
        ,
    a1
        ,
    a2
                    );
                
                    // TODO: triggers: Warning: QScriptEngine::newVariant(): changing class of non-QScriptObject not supported:
                    result = engine->newVariant(context->thisObject(), qVariantFromValue(cppResult));
                
        cppResult->__qtscript_self = result;
    
    } else 

    {
       return REcmaHelper::throwError(
       QString::fromLatin1("RFileImporterAdapter(): no matching constructor found."),
           context);
    }
    
    return result;
    }
    

    // conversion functions for base classes:
     QScriptValue REcmaFileImporterAdapter::getRFileImporter(QScriptContext *context,
            QScriptEngine *engine)
        
            {
                RFileImporter* cppResult =
                    qscriptvalue_cast<RFileImporterAdapter*> (context->thisObject());
                QScriptValue result = qScriptValueFromValue(engine, cppResult);
                return result;
            }
             QScriptValue REcmaFileImporterAdapter::getRImporter(QScriptContext *context,
            QScriptEngine *engine)
        
            {
                RImporter* cppResult =
                    qscriptvalue_cast<RFileImporterAdapter*> (context->thisObject());
                QScriptValue result = qScriptValueFromValue(engine, cppResult);
                return result;
            }
            

    // returns class name:
     QScriptValue REcmaFileImporterAdapter::getClassName(QScriptContext *context, QScriptEngine *engine) 
        
    {
        return qScriptValueFromValue(engine, QString("RFileImporterAdapter"));
    }
    

    // returns all base classes (in case of multiple inheritance):
     QScriptValue REcmaFileImporterAdapter::getBaseClasses(QScriptContext *context, QScriptEngine *engine) 
        
    {
        QStringList list;
        
        list.append("RFileImporter");
    
        list.append("RImporter");
    

        return qScriptValueFromSequence(engine, list);
    }
    

    // properties:
    

    // public methods:
     QScriptValue
        REcmaFileImporterAdapter::importFile
        (QScriptContext* context, QScriptEngine* engine) 
        
        {
            //REcmaHelper::functionStart("REcmaFileImporterAdapter::importFile", context, engine);
            //qDebug() << "ECMAScript WRAPPER: REcmaFileImporterAdapter::importFile";
            //QCoreApplication::processEvents();

            QScriptValue result = engine->undefinedValue();
            
                    // public function: can be called from ECMA wrapper of ECMA shell:
                    RFileImporterAdapter* self = 
                        getSelf("importFile", context);
                  

                //Q_ASSERT(self!=NULL);
                if (self==NULL) {
                    return REcmaHelper::throwError("self is NULL", context);
                }
                
    
    if( context->argumentCount() ==
    2 && (
            context->argument(0).isString()
        ) /* type: QString */
     && (
            context->argument(1).isString()
        ) /* type: QString */
    
    ){
    // prepare arguments:
    
                    // argument isStandardType
                    QString
                    a0 =
                    (QString)
                    
                    context->argument( 0 ).
                    toString();
                
                    // argument isStandardType
                    QString
                    a1 =
                    (QString)
                    
                    context->argument( 1 ).
                    toString();
                
    // end of arguments

    // call C++ function:
    // return type 'bool'
    bool cppResult =
        
               self->importFile(a0
        ,
    a1);
        // return type: bool
                // standard Type
                result = QScriptValue(cppResult);
            
    } else


        
            {
               return REcmaHelper::throwError("Wrong number/types of arguments for RFileImporterAdapter.importFile().",
                   context);
            }
            //REcmaHelper::functionEnd("REcmaFileImporterAdapter::importFile", context, engine);
            return result;
        }
         QScriptValue REcmaFileImporterAdapter::toString
    (QScriptContext *context, QScriptEngine *engine)
    
    {

    RFileImporterAdapter* self = getSelf("toString", context);
    
    QString result;
    
            result = QString("RFileImporterAdapter(0x%1)").arg((unsigned long int)self, 0, 16);
        
    return QScriptValue(result);
    }
     QScriptValue REcmaFileImporterAdapter::destroy(QScriptContext *context, QScriptEngine *engine)
    
    {

        RFileImporterAdapter* self = getSelf("RFileImporterAdapter", context);
        //Q_ASSERT(self!=NULL);
        if (self==NULL) {
            return REcmaHelper::throwError("self is NULL", context);
        }
        
    
        delete self;
        context->thisObject().setData(engine->nullValue());
        context->thisObject().prototype().setData(engine->nullValue());
        context->thisObject().setPrototype(engine->nullValue());
        context->thisObject().setScriptClass(NULL);
        return engine->undefinedValue();
    }
    RFileImporterAdapter* REcmaFileImporterAdapter::getSelf(const QString& fName, QScriptContext* context)
    
        {
            RFileImporterAdapter* self = NULL;

            
                // self could be a normal object (e.g. from an UI file) or
                // an ECMA shell object (made from an ECMA script):
                //self = getSelfShell(fName, context);
                

            //if (self==NULL) {
                self = REcmaHelper::scriptValueTo<RFileImporterAdapter >(context->thisObject())
                
                ;
            //}

            if (self == NULL){
                // avoid recursion (toString is used by the backtrace):
                if (fName!="toString") {
                    REcmaHelper::throwError(QString("RFileImporterAdapter.%1(): "
                        "This object is not a RFileImporterAdapter").arg(fName),
                        context);
                }
                return NULL;
            }

            return self;
        }
        REcmaShellFileImporterAdapter* REcmaFileImporterAdapter::getSelfShell(const QString& fName, QScriptContext* context)
    
        {
          RFileImporterAdapter* selfBase = getSelf(fName, context);
                REcmaShellFileImporterAdapter* self = dynamic_cast<REcmaShellFileImporterAdapter*>(selfBase);
                //return REcmaHelper::scriptValueTo<REcmaShellFileImporterAdapter >(context->thisObject());
            if(self == NULL){
                REcmaHelper::throwError(QString("RFileImporterAdapter.%1(): "
                    "This object is not a RFileImporterAdapter").arg(fName),
                    context);
            }

            return self;
            


        }
        