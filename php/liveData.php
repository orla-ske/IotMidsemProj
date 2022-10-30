<?php
require "db.php";

$query = mysqli_query($con, "SELECT * FROM waterLevel");
	while($row = mysqli_fetch_array($query)){

		$ID = $row['ID'];
		$Date = $row['Date'];
		$tankID = $row['tankID'];
		$waterLevel = $row['waterLevel'];
 ?>
			<tbody>
				<tr>
					<td><?php echo $ID; ?></td>
					<td><?php echo $Date; ?></td>
					<td><?php echo $tankID; ?></td>
					<td><?php echo $waterLevel; ?></td>
				</tr>
			</tbody>

<?php }
?>
</table>