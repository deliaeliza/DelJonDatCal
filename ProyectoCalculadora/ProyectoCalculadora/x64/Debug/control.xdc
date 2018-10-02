<?xml version="1.0"?><doc>
<members>
<member name="T:Cola" decl="false" source="c:\users\elizabeth hernandez\documents\github\deljondatcal\proyectocalculadora\proyectocalculadora\cola.h" line="2">
Declaración de la clase Cola
</member>
<member name="T:Calculadora" decl="false" source="c:\users\elizabeth hernandez\documents\github\deljondatcal\proyectocalculadora\proyectocalculadora\calculadora.h" line="14">
<summary>Clase Calculadora, Contiene los metodos de calcular y convertir
una expresion post-fija</summary>
</member>
<member name="T:Control" decl="false" source="c:\users\elizabeth hernandez\documents\github\deljondatcal\proyectocalculadora\proyectocalculadora\control.h" line="9">
<summary>Clase control, que intermedia entre la clase calculadora y la clase interfaz
Ademas contiene metodos generales.</summary>
</member>
<member name="M:Control.#ctor" decl="false" source="c:\users\elizabeth hernandez\documents\github\deljondatcal\proyectocalculadora\proyectocalculadora\control.cpp" line="4">
<summary>Constructor de la clase </summary>
</member>
<member name="M:Control.Dispose" decl="false" source="c:\users\elizabeth hernandez\documents\github\deljondatcal\proyectocalculadora\proyectocalculadora\control.cpp" line="9">
<summary>Destructor de la clase</summary>
</member>
<member name="M:Control.esValida(std.basic_string&lt;System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte,std.char_traits{System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte},std.allocator&lt;System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte&gt;&gt;)" decl="false" source="c:\users\elizabeth hernandez\documents\github\deljondatcal\proyectocalculadora\proyectocalculadora\control.cpp" line="14">
<summary>Valida que la expresion entrefija digitada por el usuario es valida,
Este metodo llama a otro metodo que valida la expresion, pero le pasa una posicion por parametro</summary>
<remarks>Recibe por paramtro un string con la expresion</remarks>
<returns>Retorna un bool</returns>
</member>
<member name="M:Control.esValida(System.UInt32,std.basic_string&lt;System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte,std.char_traits{System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte},std.allocator&lt;System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte&gt;&gt;)" decl="false" source="c:\users\elizabeth hernandez\documents\github\deljondatcal\proyectocalculadora\proyectocalculadora\control.cpp" line="22">
<summary>Valida que la expresion entrefija digitada por el usuario es valida</summary>
<remarks>Recbie una posicion, y la expresion entrefija a validar</remarks>
<returns>Retorna un bool, true si la expresion en valida, false si no</returns>
</member>
<member name="M:Control.esOperador(System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte)" decl="false" source="c:\users\elizabeth hernandez\documents\github\deljondatcal\proyectocalculadora\proyectocalculadora\control.cpp" line="70">
<summary>Metodo que valida si un char es un operador</summary>
<remarks>Recibe por parametro un char, con la expresion</remarks>
<returns>Retorna true si es operador, false si no</returns>
</member>
<member name="M:Control.removerEspacios(std.basic_string&lt;System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte,std.char_traits{System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte},std.allocator&lt;System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte&gt;&gt;*!System.Runtime.CompilerServices.IsImplicitlyDereferenced)" decl="false" source="c:\users\elizabeth hernandez\documents\github\deljondatcal\proyectocalculadora\proyectocalculadora\control.cpp" line="77">
<summary>Remueve espacios de un string</summary>
<remarks>Recibe la direccion de memoria de la expresion entre fija</remarks>
</member>
<member name="M:Control.pasarExpresionLista(std.basic_string&lt;System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte,std.char_traits{System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte},std.allocator&lt;System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte&gt;&gt;,Lista*!System.Runtime.CompilerServices.IsImplicitlyDereferenced)" decl="false" source="c:\users\elizabeth hernandez\documents\github\deljondatcal\proyectocalculadora\proyectocalculadora\control.cpp" line="90">
<summary>Pasa la cadena que contiene la expresion entrefija a una lista</summary>
<remarks>Llena una lista de caracteres</remarks>
</member>
<member name="M:Control.obtenerResultado(std.basic_string&lt;System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte,std.char_traits{System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte},std.allocator&lt;System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte&gt;&gt;)" decl="false" source="c:\users\elizabeth hernandez\documents\github\deljondatcal\proyectocalculadora\proyectocalculadora\control.cpp" line="97">
<summary>Metodo que es llamado de la interfaz, en donde obtiene el resultado
en donde encapsula varios metodos</summary>
<remarks>Recibe por parametro la expresion entre-fija</remarks>
<returns>Devuelve el resultado final</returns>
</member>
<member name="M:Control.obtenerPostFija" decl="false" source="c:\users\elizabeth hernandez\documents\github\deljondatcal\proyectocalculadora\proyectocalculadora\control.cpp" line="115">
<summary>Metodo que devuelve la cadena que contiene la expresion post-fija</summary>
<returns>Devuelve un string con la expresion post-fija</returns>
</member>
</members>
</doc>