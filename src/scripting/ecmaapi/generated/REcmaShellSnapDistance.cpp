


	// ***** AUTOGENERATED CODE, DO NOT EDIT *****
    
        #include "REcmaShellSnapDistance.h"
        #include "RMetaTypes.h"
        #include "../REcmaHelper.h"

        // forwards declarations mapped to includes
        
                #include "RGraphicsView.h"
            
                #include "RMouseEvent.h"
            
            
        // includes for base ecma wrapper classes
        
            #include "REcmaSnapEntityBase.h"
          

            #define QTSCRIPT_IS_GENERATED_FUNCTION(fun) ((fun.data().toUInt32() & 0xFFFF0000) == 0xBABE0000)
            #define QTSCRIPT_IS_FUNCTION_IN_CALL(fun) ((fun.data().toUInt32() & 0x0000F000) == 0x0000B000)

        
    // Destructor:
    REcmaShellSnapDistance::~REcmaShellSnapDistance() {}
        RSnapDistance* REcmaShellSnapDistance::getSelf(const QString& fName, QScriptContext* context)
    
        {
            RSnapDistance* self = NULL;

            
                // self could be a normal object (e.g. from an UI file) or
                // an ECMA shell object (made from an ECMA script):
                //self = getSelfShell(fName, context);
                

            //if (self==NULL) {
                self = REcmaHelper::scriptValueTo<RSnapDistance >(context->thisObject())
                
                ;
            //}

            if (self == NULL){
                // avoid recursion (toString is used by the backtrace):
                if (fName!="toString") {
                    REcmaHelper::throwError(QString("RSnapDistance.%1(): "
                        "This object is not a RSnapDistance").arg(fName),
                        context);
                }
                return NULL;
            }

            return self;
        }
        REcmaShellSnapDistance* REcmaShellSnapDistance::getSelfShell(const QString& fName, QScriptContext* context)
    
        {
          RSnapDistance* selfBase = getSelf(fName, context);
                REcmaShellSnapDistance* self = dynamic_cast<REcmaShellSnapDistance*>(selfBase);
                //return REcmaHelper::scriptValueTo<REcmaShellSnapDistance >(context->thisObject());
            if(self == NULL){
                REcmaHelper::throwError(QString("RSnapDistance.%1(): "
                    "This object is not a RSnapDistance").arg(fName),
                    context);
            }

            return self;
            


        }
        
    
    
    // Constructors:
    
      REcmaShellSnapDistance::REcmaShellSnapDistance(
                
            ) : RSnapDistance(
                
                ) {
            }
        
    
    
      void REcmaShellSnapDistance::showUiOptions(
                
            ) {
                QScriptEngine* engine = __qtscript_self.engine();
                //REcmaHelper::shellFunctionStart("REcmaShellSnapDistance::showUiOptions", engine);
                QScriptValue _q_function = __qtscript_self.property("showUiOptions");



                if (!_q_function.isFunction() || 
                    QTSCRIPT_IS_GENERATED_FUNCTION(_q_function) ||
                    QTSCRIPT_IS_FUNCTION_IN_CALL(_q_function)
                    
                    /* function might have more arguments than expected:
                    || _q_function.property("length").toInt32()!=0*/
                    /*|| (__qtscript_self.propertyFlags("atEnd") & QScriptValue::QObjectMember)*/
                    ) {
                    //QString cppSig = "RSnapDistance::showUiOptions";
                    
                        // re-enable recursion for calls from C++ into ECMAScript functions
                        // leave it marked as generated though if appropriate:
                        
                        quint32 prev = _q_function.data().toUInt32();
                        //if (cppSig!="RGraphicsViewQt::event") {
                            _q_function.setData(QScriptValue(engine, prev & 0xFFFF0000));
                        //}
                        RSnapDistance::showUiOptions(
                            
                        );

                        // block recursion again:
                        _q_function.setData(QScriptValue(engine, prev));

                        //REcmaHelper::shellFunctionEnd("REcmaShellSnapDistance::showUiOptions", engine);

                        
                            return;
                          
                }
                    // prevent recursion if script implementation calls base implementation
                    // mark function as 'in call':
                    quint32 prev = _q_function.data().toUInt32();
                    _q_function.setData(QScriptValue(engine, uint(prev | 0x0000B000)));
                    
                            _q_function.call(__qtscript_self)
                        
                    ;
                    _q_function.setData(QScriptValue(engine, prev));

                    //REcmaHelper::shellFunctionEnd("REcmaShellSnapDistance::showUiOptions", engine);

                    
            }
        
    
    
      void REcmaShellSnapDistance::hideUiOptions(
                
            ) {
                QScriptEngine* engine = __qtscript_self.engine();
                //REcmaHelper::shellFunctionStart("REcmaShellSnapDistance::hideUiOptions", engine);
                QScriptValue _q_function = __qtscript_self.property("hideUiOptions");



                if (!_q_function.isFunction() || 
                    QTSCRIPT_IS_GENERATED_FUNCTION(_q_function) ||
                    QTSCRIPT_IS_FUNCTION_IN_CALL(_q_function)
                    
                    /* function might have more arguments than expected:
                    || _q_function.property("length").toInt32()!=0*/
                    /*|| (__qtscript_self.propertyFlags("atEnd") & QScriptValue::QObjectMember)*/
                    ) {
                    //QString cppSig = "RSnapDistance::hideUiOptions";
                    
                        // re-enable recursion for calls from C++ into ECMAScript functions
                        // leave it marked as generated though if appropriate:
                        
                        quint32 prev = _q_function.data().toUInt32();
                        //if (cppSig!="RGraphicsViewQt::event") {
                            _q_function.setData(QScriptValue(engine, prev & 0xFFFF0000));
                        //}
                        RSnapDistance::hideUiOptions(
                            
                        );

                        // block recursion again:
                        _q_function.setData(QScriptValue(engine, prev));

                        //REcmaHelper::shellFunctionEnd("REcmaShellSnapDistance::hideUiOptions", engine);

                        
                            return;
                          
                }
                    // prevent recursion if script implementation calls base implementation
                    // mark function as 'in call':
                    quint32 prev = _q_function.data().toUInt32();
                    _q_function.setData(QScriptValue(engine, uint(prev | 0x0000B000)));
                    
                            _q_function.call(__qtscript_self)
                        
                    ;
                    _q_function.setData(QScriptValue(engine, prev));

                    //REcmaHelper::shellFunctionEnd("REcmaShellSnapDistance::hideUiOptions", engine);

                    
            }
        
    
    
      void REcmaShellSnapDistance::setDistance(
                double d
            ) {
                QScriptEngine* engine = __qtscript_self.engine();
                //REcmaHelper::shellFunctionStart("REcmaShellSnapDistance::setDistance", engine);
                QScriptValue _q_function = __qtscript_self.property("setDistance");



                if (!_q_function.isFunction() || 
                    QTSCRIPT_IS_GENERATED_FUNCTION(_q_function) ||
                    QTSCRIPT_IS_FUNCTION_IN_CALL(_q_function)
                    
                    /* function might have more arguments than expected:
                    || _q_function.property("length").toInt32()!=1*/
                    /*|| (__qtscript_self.propertyFlags("atEnd") & QScriptValue::QObjectMember)*/
                    ) {
                    //QString cppSig = "RSnapDistance::setDistance";
                    
                        // re-enable recursion for calls from C++ into ECMAScript functions
                        // leave it marked as generated though if appropriate:
                        
                        quint32 prev = _q_function.data().toUInt32();
                        //if (cppSig!="RGraphicsViewQt::event") {
                            _q_function.setData(QScriptValue(engine, prev & 0xFFFF0000));
                        //}
                        RSnapDistance::setDistance(
                            d
                        );

                        // block recursion again:
                        _q_function.setData(QScriptValue(engine, prev));

                        //REcmaHelper::shellFunctionEnd("REcmaShellSnapDistance::setDistance", engine);

                        
                            return;
                          
                }
                    // prevent recursion if script implementation calls base implementation
                    // mark function as 'in call':
                    quint32 prev = _q_function.data().toUInt32();
                    _q_function.setData(QScriptValue(engine, uint(prev | 0x0000B000)));
                    
                            _q_function.call(__qtscript_self,
                                QScriptValueList()
                                



    // type: double, copyable: true
        << qScriptValueFromValue(engine, 

        d
        )
      
                            )
                        
                    ;
                    _q_function.setData(QScriptValue(engine, prev));

                    //REcmaHelper::shellFunctionEnd("REcmaShellSnapDistance::setDistance", engine);

                    
            }
        
    
    
      QList < RVector > REcmaShellSnapDistance::snapEntity(
                QSharedPointer < REntity > entity, const RVector & point, const RBox & queryBox, RGraphicsView & view
            ) {
                QScriptEngine* engine = __qtscript_self.engine();
                //REcmaHelper::shellFunctionStart("REcmaShellSnapDistance::snapEntity", engine);
                QScriptValue _q_function = __qtscript_self.property("snapEntity");



                if (!_q_function.isFunction() || 
                    QTSCRIPT_IS_GENERATED_FUNCTION(_q_function) ||
                    QTSCRIPT_IS_FUNCTION_IN_CALL(_q_function)
                    
                    /* function might have more arguments than expected:
                    || _q_function.property("length").toInt32()!=4*/
                    /*|| (__qtscript_self.propertyFlags("atEnd") & QScriptValue::QObjectMember)*/
                    ) {
                    //QString cppSig = "RSnapDistance::snapEntity";
                    
                        // re-enable recursion for calls from C++ into ECMAScript functions
                        // leave it marked as generated though if appropriate:
                        
                        quint32 prev = _q_function.data().toUInt32();
                        //if (cppSig!="RGraphicsViewQt::event") {
                            _q_function.setData(QScriptValue(engine, prev & 0xFFFF0000));
                        //}
                        QList < RVector > ret =
                        RSnapDistance::snapEntity(
                            entity, point, queryBox, view
                        );

                        // block recursion again:
                        _q_function.setData(QScriptValue(engine, prev));

                        //REcmaHelper::shellFunctionEnd("REcmaShellSnapDistance::snapEntity", engine);

                        
                            return ret;
                          
                }
                    // prevent recursion if script implementation calls base implementation
                    // mark function as 'in call':
                    quint32 prev = _q_function.data().toUInt32();
                    _q_function.setData(QScriptValue(engine, uint(prev | 0x0000B000)));
                    
                        // temporary make protected function scriptable, only from the context of this function call:
                        QScriptValue proto = engine->defaultPrototype(qMetaTypeId<RSnapDistance*>());
                        REcmaHelper::registerFunction(engine, &proto, snapEntity, "snapEntity");
                        QList < RVector > res;
                      
                          REcmaHelper::fromScriptValue(engine, 
                        
                            _q_function.call(__qtscript_self,
                                QScriptValueList()
                                



    // type: QSharedPointer < REntity >, copyable: false
        << qScriptValueFromValue(engine, 

        entity
        )
      



    // type: RVector &, copyable: true
        << qScriptValueFromValue(engine, 

        
            // const reference argument - make a new object:
            new RVector(point)
        )
      



    // type: RBox &, copyable: true
        << qScriptValueFromValue(engine, 

        
            // const reference argument - make a new object:
            new RBox(queryBox)
        )
      



    // type: RGraphicsView &, copyable: false
        << qScriptValueFromValue(engine, 

        &view
        )
      
                            )
                        
                      , res
                    
                      )
                    
                    ;
                    _q_function.setData(QScriptValue(engine, prev));

                    //REcmaHelper::shellFunctionEnd("REcmaShellSnapDistance::snapEntity", engine);

                    
                            return res;
                          
            }
        
    
  
        // methods of 1st level base class RSnapEntityBase:
        
      RVector REcmaShellSnapDistance::snap(
                const RVector & position, RGraphicsView & view, double range
            ) {
                QScriptEngine* engine = __qtscript_self.engine();
                //REcmaHelper::shellFunctionStart("REcmaShellSnapDistance::snap", engine);
                QScriptValue _q_function = __qtscript_self.property("snap");



                if (!_q_function.isFunction() || 
                    QTSCRIPT_IS_GENERATED_FUNCTION(_q_function) ||
                    QTSCRIPT_IS_FUNCTION_IN_CALL(_q_function)
                    
                    /* function might have more arguments than expected:
                    || _q_function.property("length").toInt32()!=3*/
                    /*|| (__qtscript_self.propertyFlags("atEnd") & QScriptValue::QObjectMember)*/
                    ) {
                    //QString cppSig = "RSnapDistance::snap";
                    
                        // re-enable recursion for calls from C++ into ECMAScript functions
                        // leave it marked as generated though if appropriate:
                        
                        quint32 prev = _q_function.data().toUInt32();
                        //if (cppSig!="RGraphicsViewQt::event") {
                            _q_function.setData(QScriptValue(engine, prev & 0xFFFF0000));
                        //}
                        RVector ret =
                        RSnapDistance::snap(
                            position, view, range
                        );

                        // block recursion again:
                        _q_function.setData(QScriptValue(engine, prev));

                        //REcmaHelper::shellFunctionEnd("REcmaShellSnapDistance::snap", engine);

                        
                            return ret;
                          
                }
                    // prevent recursion if script implementation calls base implementation
                    // mark function as 'in call':
                    quint32 prev = _q_function.data().toUInt32();
                    _q_function.setData(QScriptValue(engine, uint(prev | 0x0000B000)));
                    RVector res;
                      
                          res = qscriptvalue_cast< 
                            RVector
                          >(
                        
                            _q_function.call(__qtscript_self,
                                QScriptValueList()
                                



    // type: RVector &, copyable: true
        << qScriptValueFromValue(engine, 

        
            // const reference argument - make a new object:
            new RVector(position)
        )
      



    // type: RGraphicsView &, copyable: false
        << qScriptValueFromValue(engine, 

        &view
        )
      



    // type: double, copyable: true
        << qScriptValueFromValue(engine, 

        range
        )
      
                            )
                        
                      )
                    
                    ;
                    _q_function.setData(QScriptValue(engine, prev));

                    //REcmaHelper::shellFunctionEnd("REcmaShellSnapDistance::snap", engine);

                    
                            return res;
                          
            }
        
      RVector REcmaShellSnapDistance::snap(
                const RVector & position, RGraphicsView & view, const QSet < REntity::Id > & candidates, const RBox & queryBox
            ) {
                QScriptEngine* engine = __qtscript_self.engine();
                //REcmaHelper::shellFunctionStart("REcmaShellSnapDistance::snap", engine);
                QScriptValue _q_function = __qtscript_self.property("snap");



                if (!_q_function.isFunction() || 
                    QTSCRIPT_IS_GENERATED_FUNCTION(_q_function) ||
                    QTSCRIPT_IS_FUNCTION_IN_CALL(_q_function)
                    
                    /* function might have more arguments than expected:
                    || _q_function.property("length").toInt32()!=4*/
                    /*|| (__qtscript_self.propertyFlags("atEnd") & QScriptValue::QObjectMember)*/
                    ) {
                    //QString cppSig = "RSnapDistance::snap";
                    
                        // re-enable recursion for calls from C++ into ECMAScript functions
                        // leave it marked as generated though if appropriate:
                        
                        quint32 prev = _q_function.data().toUInt32();
                        //if (cppSig!="RGraphicsViewQt::event") {
                            _q_function.setData(QScriptValue(engine, prev & 0xFFFF0000));
                        //}
                        RVector ret =
                        RSnapDistance::snap(
                            position, view, candidates, queryBox
                        );

                        // block recursion again:
                        _q_function.setData(QScriptValue(engine, prev));

                        //REcmaHelper::shellFunctionEnd("REcmaShellSnapDistance::snap", engine);

                        
                            return ret;
                          
                }
                    // prevent recursion if script implementation calls base implementation
                    // mark function as 'in call':
                    quint32 prev = _q_function.data().toUInt32();
                    _q_function.setData(QScriptValue(engine, uint(prev | 0x0000B000)));
                    RVector res;
                      
                          res = qscriptvalue_cast< 
                            RVector
                          >(
                        
                            _q_function.call(__qtscript_self,
                                QScriptValueList()
                                



    // type: RVector &, copyable: true
        << qScriptValueFromValue(engine, 

        
            // const reference argument - make a new object:
            new RVector(position)
        )
      



    // type: RGraphicsView &, copyable: false
        << qScriptValueFromValue(engine, 

        &view
        )
      



    // type: QSet < REntity::Id > &, copyable: false
        << qScriptValueFromValue(engine, 

        
            // const reference argument - make a new object:
            new QSet < REntity::Id >(candidates)
        )
      



    // type: RBox &, copyable: true
        << qScriptValueFromValue(engine, 

        
            // const reference argument - make a new object:
            new RBox(queryBox)
        )
      
                            )
                        
                      )
                    
                    ;
                    _q_function.setData(QScriptValue(engine, prev));

                    //REcmaHelper::shellFunctionEnd("REcmaShellSnapDistance::snap", engine);

                    
                            return res;
                          
            }
        
    
            // methods of 2nd level base class RSnap:
            
      QSet < REntity::Id > REcmaShellSnapDistance::getEntityIds(
                
            ) {
                QScriptEngine* engine = __qtscript_self.engine();
                //REcmaHelper::shellFunctionStart("REcmaShellSnapDistance::getEntityIds", engine);
                QScriptValue _q_function = __qtscript_self.property("getEntityIds");



                if (!_q_function.isFunction() || 
                    QTSCRIPT_IS_GENERATED_FUNCTION(_q_function) ||
                    QTSCRIPT_IS_FUNCTION_IN_CALL(_q_function)
                    
                    /* function might have more arguments than expected:
                    || _q_function.property("length").toInt32()!=0*/
                    /*|| (__qtscript_self.propertyFlags("atEnd") & QScriptValue::QObjectMember)*/
                    ) {
                    //QString cppSig = "RSnapDistance::getEntityIds";
                    
                        // re-enable recursion for calls from C++ into ECMAScript functions
                        // leave it marked as generated though if appropriate:
                        
                        quint32 prev = _q_function.data().toUInt32();
                        //if (cppSig!="RGraphicsViewQt::event") {
                            _q_function.setData(QScriptValue(engine, prev & 0xFFFF0000));
                        //}
                        QSet < REntity::Id > ret =
                        RSnapDistance::getEntityIds(
                            
                        );

                        // block recursion again:
                        _q_function.setData(QScriptValue(engine, prev));

                        //REcmaHelper::shellFunctionEnd("REcmaShellSnapDistance::getEntityIds", engine);

                        
                            return ret;
                          
                }
                    // prevent recursion if script implementation calls base implementation
                    // mark function as 'in call':
                    quint32 prev = _q_function.data().toUInt32();
                    _q_function.setData(QScriptValue(engine, uint(prev | 0x0000B000)));
                    QSet < REntity::Id > res;
                      
                          res = qscriptvalue_cast< 
                            QSet < REntity::Id >
                          >(
                        
                            _q_function.call(__qtscript_self)
                        
                      )
                    
                    ;
                    _q_function.setData(QScriptValue(engine, prev));

                    //REcmaHelper::shellFunctionEnd("REcmaShellSnapDistance::getEntityIds", engine);

                    
                            return res;
                          
            }
        
    
      RSnap::Status REcmaShellSnapDistance::getStatus(
                
            ) {
                QScriptEngine* engine = __qtscript_self.engine();
                //REcmaHelper::shellFunctionStart("REcmaShellSnapDistance::getStatus", engine);
                QScriptValue _q_function = __qtscript_self.property("getStatus");



                if (!_q_function.isFunction() || 
                    QTSCRIPT_IS_GENERATED_FUNCTION(_q_function) ||
                    QTSCRIPT_IS_FUNCTION_IN_CALL(_q_function)
                    
                    /* function might have more arguments than expected:
                    || _q_function.property("length").toInt32()!=0*/
                    /*|| (__qtscript_self.propertyFlags("atEnd") & QScriptValue::QObjectMember)*/
                    ) {
                    //QString cppSig = "RSnapDistance::getStatus";
                    
                        // re-enable recursion for calls from C++ into ECMAScript functions
                        // leave it marked as generated though if appropriate:
                        
                        quint32 prev = _q_function.data().toUInt32();
                        //if (cppSig!="RGraphicsViewQt::event") {
                            _q_function.setData(QScriptValue(engine, prev & 0xFFFF0000));
                        //}
                        RSnap::Status ret =
                        RSnapDistance::getStatus(
                            
                        );

                        // block recursion again:
                        _q_function.setData(QScriptValue(engine, prev));

                        //REcmaHelper::shellFunctionEnd("REcmaShellSnapDistance::getStatus", engine);

                        
                            return ret;
                          
                }
                    // prevent recursion if script implementation calls base implementation
                    // mark function as 'in call':
                    quint32 prev = _q_function.data().toUInt32();
                    _q_function.setData(QScriptValue(engine, uint(prev | 0x0000B000)));
                    RSnap::Status res;
                      
                          res = qscriptvalue_cast< 
                            RSnap::Status
                          >(
                        
                            _q_function.call(__qtscript_self)
                        
                      )
                    
                    ;
                    _q_function.setData(QScriptValue(engine, prev));

                    //REcmaHelper::shellFunctionEnd("REcmaShellSnapDistance::getStatus", engine);

                    
                            return res;
                          
            }
        
    
      RVector REcmaShellSnapDistance::getLastSnap(
                
            ) {
                QScriptEngine* engine = __qtscript_self.engine();
                //REcmaHelper::shellFunctionStart("REcmaShellSnapDistance::getLastSnap", engine);
                QScriptValue _q_function = __qtscript_self.property("getLastSnap");



                if (!_q_function.isFunction() || 
                    QTSCRIPT_IS_GENERATED_FUNCTION(_q_function) ||
                    QTSCRIPT_IS_FUNCTION_IN_CALL(_q_function)
                    
                    /* function might have more arguments than expected:
                    || _q_function.property("length").toInt32()!=0*/
                    /*|| (__qtscript_self.propertyFlags("atEnd") & QScriptValue::QObjectMember)*/
                    ) {
                    //QString cppSig = "RSnapDistance::getLastSnap";
                    
                        // re-enable recursion for calls from C++ into ECMAScript functions
                        // leave it marked as generated though if appropriate:
                        
                        quint32 prev = _q_function.data().toUInt32();
                        //if (cppSig!="RGraphicsViewQt::event") {
                            _q_function.setData(QScriptValue(engine, prev & 0xFFFF0000));
                        //}
                        RVector ret =
                        RSnapDistance::getLastSnap(
                            
                        );

                        // block recursion again:
                        _q_function.setData(QScriptValue(engine, prev));

                        //REcmaHelper::shellFunctionEnd("REcmaShellSnapDistance::getLastSnap", engine);

                        
                            return ret;
                          
                }
                    // prevent recursion if script implementation calls base implementation
                    // mark function as 'in call':
                    quint32 prev = _q_function.data().toUInt32();
                    _q_function.setData(QScriptValue(engine, uint(prev | 0x0000B000)));
                    RVector res;
                      
                          res = qscriptvalue_cast< 
                            RVector
                          >(
                        
                            _q_function.call(__qtscript_self)
                        
                      )
                    
                    ;
                    _q_function.setData(QScriptValue(engine, prev));

                    //REcmaHelper::shellFunctionEnd("REcmaShellSnapDistance::getLastSnap", engine);

                    
                            return res;
                          
            }
        
    
      void REcmaShellSnapDistance::reset(
                
            ) {
                QScriptEngine* engine = __qtscript_self.engine();
                //REcmaHelper::shellFunctionStart("REcmaShellSnapDistance::reset", engine);
                QScriptValue _q_function = __qtscript_self.property("reset");



                if (!_q_function.isFunction() || 
                    QTSCRIPT_IS_GENERATED_FUNCTION(_q_function) ||
                    QTSCRIPT_IS_FUNCTION_IN_CALL(_q_function)
                    
                    /* function might have more arguments than expected:
                    || _q_function.property("length").toInt32()!=0*/
                    /*|| (__qtscript_self.propertyFlags("atEnd") & QScriptValue::QObjectMember)*/
                    ) {
                    //QString cppSig = "RSnapDistance::reset";
                    
                        // re-enable recursion for calls from C++ into ECMAScript functions
                        // leave it marked as generated though if appropriate:
                        
                        quint32 prev = _q_function.data().toUInt32();
                        //if (cppSig!="RGraphicsViewQt::event") {
                            _q_function.setData(QScriptValue(engine, prev & 0xFFFF0000));
                        //}
                        RSnapDistance::reset(
                            
                        );

                        // block recursion again:
                        _q_function.setData(QScriptValue(engine, prev));

                        //REcmaHelper::shellFunctionEnd("REcmaShellSnapDistance::reset", engine);

                        
                            return;
                          
                }
                    // prevent recursion if script implementation calls base implementation
                    // mark function as 'in call':
                    quint32 prev = _q_function.data().toUInt32();
                    _q_function.setData(QScriptValue(engine, uint(prev | 0x0000B000)));
                    
                            _q_function.call(__qtscript_self)
                        
                    ;
                    _q_function.setData(QScriptValue(engine, prev));

                    //REcmaHelper::shellFunctionEnd("REcmaShellSnapDistance::reset", engine);

                    
            }
        
    

    // protected methods (only available for ECMA shell classes) (generated by xsl2xpp.xsl):
	 QScriptValue
        REcmaShellSnapDistance::snapEntity
        (QScriptContext* context, QScriptEngine* engine) 
        
        {
            //REcmaHelper::functionStart("REcmaShellSnapDistance::snapEntity", context, engine);
            //qDebug() << "ECMAScript WRAPPER: REcmaShellSnapDistance::snapEntity";
            //QCoreApplication::processEvents();

            QScriptValue result = engine->undefinedValue();
            
                    // protected function: can only be called from ECMA shell:
                    REcmaShellSnapDistance* self = 
                        getSelfShell("", context);
                  

                //Q_ASSERT(self!=NULL);
                if (self==NULL) {
                    return REcmaHelper::throwError("self is NULL", context);
                }
                
    
    if( context->argumentCount() ==
    4 && (
            context->argument(0).isVariant() || 
            context->argument(0).isQObject() || 
            context->argument(0).isNull()
        ) /* type: QSharedPointer < REntity > */
     && (
            context->argument(1).isVariant() || 
            context->argument(1).isQObject() || 
            context->argument(1).isNull()
        ) /* type: RVector */
     && (
            context->argument(2).isVariant() || 
            context->argument(2).isQObject() || 
            context->argument(2).isNull()
        ) /* type: RBox */
     && (
            context->argument(3).isVariant() || 
            context->argument(3).isQObject() || 
            context->argument(3).isNull()
        ) /* type: RGraphicsView */
    
    ){
    // prepare arguments:
    
                    // argument is SharedPointer
                    QSharedPointer < REntity > 
                    a0;

                    // argument might be a simple pointer:
                     REntity * o0 = 
                    qscriptvalue_cast < REntity * > (context->argument(0));

                    if (o0!=NULL) {
                        a0 =
                        QSharedPointer < REntity >(o0->clone());
                    }
                    else {
                        // qscriptvalue_cast to QSharedPointer<BaseClass> does not work
                        QSharedPointer < REntity >*
                        p0;

                        p0 =
                        qscriptvalue_cast <QSharedPointer < REntity >* > (context->argument(0));

                        if (p0==NULL) {
                           return REcmaHelper::throwError("RSnapDistance: Argument 0 is not of type  REntity .", context);                    
                        }

                        a0 = *p0;

                           //return REcmaHelper::throwError("RSnapDistance: Argument 0 is not of type  REntity .",
                           //    context);                    
                    }

                    //QSharedPointer < REntity > 
                    //a0 =
                    //QSharedPointer < REntity >(o0->clone());
                
                    // argument isCopyable and has default constructor and isSimpleClass 
                    RVector*
                    ap1 =
                    qscriptvalue_cast<
                    RVector*
                        >(
                        context->argument(
                        1
                        )
                    );
                    if (ap1 == NULL) {
                           return REcmaHelper::throwError("RSnapDistance: Argument 1 is not of type RVector.",
                               context);                    
                    }
                    RVector 
                    a1 = 
                    *ap1;
                
                    // argument isCopyable and has default constructor and isSimpleClass 
                    RBox*
                    ap2 =
                    qscriptvalue_cast<
                    RBox*
                        >(
                        context->argument(
                        2
                        )
                    );
                    if (ap2 == NULL) {
                           return REcmaHelper::throwError("RSnapDistance: Argument 2 is not of type RBox.",
                               context);                    
                    }
                    RBox 
                    a2 = 
                    *ap2;
                
                    // argument is reference
                    RGraphicsView*
                    ap3 =
                    qscriptvalue_cast<
                    RGraphicsView*
                        >(
                        context->argument(
                        3
                        )
                    );
                    if( ap3 == NULL ){
                           return REcmaHelper::throwError("RSnapDistance: Argument 3 is not of type RGraphicsView*.",
                               context);                    
                    }
                    RGraphicsView& a3 = *ap3;
                
    // end of arguments

    // call C++ function:
    // return type 'QList < RVector >'
    QList < RVector > cppResult =
        
               self->RSnapDistance::snapEntity(a0
        ,
    a1
        ,
    a2
        ,
    a3);
        // return type: QList < RVector >
                // List of ...:
                result = REcmaHelper::listToScriptValue(engine, cppResult);
            
    } else


        
            {
               return REcmaHelper::throwError("Wrong number/types of arguments for RSnapDistance.snapEntity().",
                   context);
            }
            //REcmaHelper::functionEnd("REcmaShellSnapDistance::snapEntity", context, engine);
            return result;
        }
        