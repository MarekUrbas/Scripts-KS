using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Strzelanie : MonoBehaviour
{
    [SerializeField] private Transform miejsceStrzalu;

    [SerializeField] private GameObject nasz_particle;

    private RaycastHit cel;

    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        if (Input.GetButton("Fire1"))
        {
            if (Physics.Raycast(miejsceStrzalu.position, miejsceStrzalu.forward, out cel))
            {
                var go = Instantiate(nasz_particle, cel.point, Quaternion.identity);
                go.transform.rotation = Quaternion.LookRotation(cel.normal.normalized);
            }
        }
    }

    
}
