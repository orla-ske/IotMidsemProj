<?php
require "db.php";


    if (!isset($_GET['tankID'])) 
        die(" tankID not specified");
    if ($_GET['tankID']=='')
        die(" tankID is blank");
    if (!is_numeric($_GET['tankID'] ) )
        die(" tankID is not numeric");
    
    $data=array();        

    $q=mysqli_query($con,"select * from tempdata where tankID={$_GET['tankID']}");    
    
    $row=mysqli_fetch_object($q);
    while ($row)
    {         
        
        echo " {$row->tankID} {$row->waterLevel}";
        $row=mysqli_fetch_object($q);
    }       
    


?>