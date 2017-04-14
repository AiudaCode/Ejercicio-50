public class Laptop
{
    // se declaran los atributos privados
    private String referencia;
    private String marca;
    private String modelo;
    private float precio;
    private float m_ram;
    private float ghz;
    
    public Laptop()
    {
        // se le asignan valores por defecto a los atributos en el constructor de la clase
        referencia = "";
        marca = "";
        modelo = "";
        precio = 0;
        m_ram = 0;
        ghz = 0;
    }
    
    // métodos Setters y Getters de los atributos de la clase
    public void setReferencia(String val)
    {
        referencia = val;
    }
    
    public String getReferencia()
    {
        return referencia;
    }
    
    public void setMarca(String val)
    {
        marca = val;
    }
    
    public String getMarca()
    {
        return marca;
    }
    
    public void setModelo(String val)
    {
        modelo = val;
    }
    
    public String getModelo()
    {
        return modelo;
    }
    
    public void setPrecio(float val)
    {
        precio = val;
    }
    
    public float getPrecio()
    {
        return precio;
    }
    
    public void setMemoriaRam(float val)
    {
        m_ram = val;
    }
    
    public float getMemoriaRam()
    {
        return m_ram;
    }
    
    public void setGhz(float val)
    {
        ghz = val;
    }
    
    public float getGhz()
    {
        return ghz;
    }
}