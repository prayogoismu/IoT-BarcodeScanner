<?php
defined('BASEPATH') OR exit('No direct script access allowed');

class Afhd extends CI_Controller {

	public function index()
	{
			$this->load->model('model_value');
			$data['val']=$this->model_value->lastrows();
			$this->load->view('dashboard/home',$data);
	}

	function status_()
	{
		$this->load->model('model_value');
		$value_=$this->input->get('value');
		//$data['val']=$value_;
		//$this->load->view('dashboard/status',$data);
		$this->model_value->save_value($value_);
		//redirect('afhd/index');
		echo "succes";
	}

	function status()
	{
		$this->load->model('model_value');
		$data['val']=$this->model_value->lastrows();
		$this->load->view('dashboard/status',$data);
	}


}