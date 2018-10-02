<?xml version="1.0"?><doc>
<members>
<member name="T:Cola" decl="false" source="c:\users\aleid\onedrive\documentos\github\deljondatcal\proyectocalculadora\proyectocalculadora\cola.h" line="2">
Declaración de la clase Cola
</member>
<member name="T:Calculadora" decl="false" source="c:\users\aleid\onedrive\documentos\github\deljondatcal\proyectocalculadora\proyectocalculadora\calculadora.h" line="14">
<summary>Clase Calculadora, Contiene los metodos de calcular y convertir
una expresion post-fija</summary>
</member>
<member name="M:Calculadora.#ctor" decl="false" source="c:\users\aleid\onedrive\documentos\github\deljondatcal\proyectocalculadora\proyectocalculadora\calculadora.cpp" line="3">
<summary>Constructor de clase, Inicializa un string, y la cola</summary>
</member>
<member name="M:Calculadora.Dispose" decl="false" source="c:\users\aleid\onedrive\documentos\github\deljondatcal\proyectocalculadora\proyectocalculadora\calculadora.cpp" line="8">
<summary>Destructor de la clase</summary>
</member>
<member name="M:Calculadora.getCadenaPostFija" decl="false" source="c:\users\aleid\onedrive\documentos\github\deljondatcal\proyectocalculadora\proyectocalculadora\calculadora.cpp" line="13">
<summary>Devuelve el string que contiene la cadena postfija</summary>
</member>
<member name="M:Calculadora.resultado(Lista*!System.Runtime.CompilerServices.IsImplicitlyDereferenced)" decl="false" source="c:\users\aleid\onedrive\documentos\github\deljondatcal\proyectocalculadora\proyectocalculadora\calculadora.cpp" line="18">
<summary>Devuelve el resultado de evaluar la cadena postfija</summary>
<remarks>Recibe una lista por referencia</remarks>
<returns>Retorna un double con el resultado</returns>
</member>
<member name="M:Calculadora.convertirExpresionPostFija(Lista*!System.Runtime.CompilerServices.IsImplicitlyDereferenced)" decl="false" source="c:\users\aleid\onedrive\documentos\github\deljondatcal\proyectocalculadora\proyectocalculadora\calculadora.cpp" line="31">
<summary>Metodo que llama al metodo que convierte a expresion post-fija</summary>
<remarks>Recibe una lista por referencia</remarks>
</member>
<member name="M:Calculadora.convertirInterFijaPostFija(Pila&lt;System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte&gt;,Nodo*)" decl="false" source="c:\users\aleid\onedrive\documentos\github\deljondatcal\proyectocalculadora\proyectocalculadora\calculadora.cpp" line="39">
<summary>Metodo recursivo que convierte la expresion entrefija a una expresion postfija</summary>
<remarks>Recibe una pila, y el primer elemento de la lista</remarks>
</member>
<member name="M:Calculadora.precedencia(System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte)" decl="false" source="c:\users\aleid\onedrive\documentos\github\deljondatcal\proyectocalculadora\proyectocalculadora\calculadora.cpp" line="140">
<summary>Consulta el operador de mayor importancia</summary>
<remarks>Recibe un operador valido, ya sea +,-,^,*,/,(</remarks>
<returns>Retorna un numero entero</returns>
</member>
<member name="M:Calculadora.convertirString(System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte)" decl="false" source="c:\users\aleid\onedrive\documentos\github\deljondatcal\proyectocalculadora\proyectocalculadora\calculadora.cpp" line="155">
<summary>Convierte un char a un string</summary>
<remarks>Recibe un char</remarks>
<returns>Devuelve un string</returns>
</member>
<member name="M:Calculadora.resultado(Cola*,Pila&lt;System.Double&gt;)" decl="false" source="c:\users\aleid\onedrive\documentos\github\deljondatcal\proyectocalculadora\proyectocalculadora\calculadora.cpp" line="164">
<summary>Calcula el resultado de la expresion postfija</summary>
<remarks>Recibe una cola, en la que esta la expresion postfija, y recibe una pila, en la que guardara 
los numeros de la expresion</remarks>
<returns>Devuelve un double con el resultado</returns>
</member>
<member name="M:Calculadora.unificarSignos(std.basic_string&lt;System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte,std.char_traits{System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte},std.allocator&lt;System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte&gt;&gt;,std.basic_string&lt;System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte,std.char_traits{System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte},std.allocator&lt;System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte&gt;&gt;)" decl="false" source="c:\users\aleid\onedrive\documentos\github\deljondatcal\proyectocalculadora\proyectocalculadora\calculadora.cpp" line="233">
<summary>Resuelve signos de + y -</summary>
<remarks>Recibe el signo actual, y el anterior</remarks>
<returns>Devuelve un string con el resultado de resolver los signos anteriores</returns>
</member>
<member name="M:Calculadora.esOperador(std.basic_string&lt;System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte,std.char_traits{System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte},std.allocator&lt;System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte&gt;&gt;)" decl="false" source="c:\users\aleid\onedrive\documentos\github\deljondatcal\proyectocalculadora\proyectocalculadora\calculadora.cpp" line="248">
<summary>Verifica que un valor, es un operador o no</summary>
<remarks>Recibe un string con un valor actual</remarks>
<returns>Devuelve un bool con la verficacion</returns>
</member>
<member name="M:Calculadora.realizarOperacion(System.Double,System.Double,std.basic_string&lt;System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte,std.char_traits{System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte},std.allocator&lt;System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte&gt;&gt;)" decl="false" source="c:\users\aleid\onedrive\documentos\github\deljondatcal\proyectocalculadora\proyectocalculadora\calculadora.cpp" line="255">
<summary>Realiza una operacion</summary>
<remarks>Recibe dos numeros y un operador</remarks>
<returns>Devuelve un double</returns>
</member>
<member name="M:Calculadora.convertir(std.basic_string&lt;System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte,std.char_traits{System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte},std.allocator&lt;System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte&gt;&gt;)" decl="false" source="c:\users\aleid\onedrive\documentos\github\deljondatcal\proyectocalculadora\proyectocalculadora\calculadora.cpp" line="272">
<summary>Convierte un string a un numero</summary>
<remarks>Recibe un string que contiene un numero</remarks>
<returns>Devuelve un double con el numero convertido</returns>
</member>
</members>
</doc>