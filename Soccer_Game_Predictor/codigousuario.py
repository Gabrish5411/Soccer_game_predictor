import sim_futbol as sf

def mireporte(e1,e2):
    p=sf.partido(e1,e2)
    s=sf.simulacion(p,100000)
    print(s.reporte())
    
    r=(-1,-1,0)
    pgoleada=0
    for i in range(10):
        for j in range(10):
            p=s.p_resultado(i,j)
            if p>r[-1]:
                r=(i,j,p)
            if i+j>=4:
                pgoleada+=p
    
    print("El resultado más probable es",r[0],"-",r[1])
    print("Con una probabilidad de {:5.2f}%".format(100*r[2]))
    print("La probabilidad de que haya 4 o más goles es {:5.2f}%".format(100*pgoleada))

mireporte(sf.equipo("Brasil", 2154),
          sf.equipo("Argentina", 2023))

mireporte(sf.equipo("Inglaterra", 2040),
          sf.equipo("Italia", 2088))