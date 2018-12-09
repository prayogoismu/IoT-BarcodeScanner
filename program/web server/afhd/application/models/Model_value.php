<?php
class Model_value extends CI_Model{
	
	function __construct()
	{
		parent::__construct();
	}

	function save_value($value_)
	{
		$channel="nilai_afhd";
		$rows=array(
			'value'=>$value_,
		);

		$this->db->insert($channel,$rows); 
		return true;
	}

	function lastrows(){
		$channel="nilai_afhd";
		$q="select * from $channel order by tanggal desc limit 1";
		$query = $this->db->query($q);

		//mengembalikan query result tepat 1 record
		//pada hal.view tidak perlu definisi foreach
		return $query->row_array(); 
	}	

	function edit_table($value)
	{
		$data=array(
			'value'=>$value,
			);
		$table_channel="nilai_afhd";
		$this->db->where('id',"id");
		$this->db->update($table_channel,$data);
	}
}
?>