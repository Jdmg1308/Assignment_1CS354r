using Godot;
using System;

public partial class Audio : AudioStreamPlayer3D
{
	// Called when the node enters the scene tree for the first time.
	public override void _Ready()
	{
	}

	// Called every frame. 'delta' is the elapsed time since the previous frame.
	public override void _Process(double delta)
	{
	}

	public void _on_wall_wall_hit() {
		
		if (GD.Randf() >= 0.5) {
			this.Stream = ResourceLoader.Load<AudioStream>("res://soundfx/UI Soundpack/MP3/Minimalist11.mp3");
		} else {
			this.Stream = ResourceLoader.Load<AudioStream>("res://soundfx/UI Soundpack/MP3/Minimalist3.mp3");
		}
		this.Play();
	}

	public void _on_ball_ball_hit() {
		this.Stream = ResourceLoader.Load<AudioStream>("res://soundfx/UI Soundpack/MP3/Retro1.mp3");
		this.Play();
	}
}
