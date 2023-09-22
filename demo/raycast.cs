using Godot;
using System;

public partial class raycast : RayCast3D
{
    public override void _Ready()
    {
        // Ensure that the RayCast node is enabled.
        // rayCast = GetNode<RayCast3D>("Camera3D/RayCast3D");
		Enabled = true;
    }

    public override void _Input(InputEvent @event)
    {
        if (@event is InputEventMouseButton mouseEvent && mouseEvent.Pressed)
        {
            if (mouseEvent.ButtonIndex == MouseButton.Left)
            {
                // Get the mouse position in the viewport.
                var mousePosition = GetViewport().GetMousePosition();

                // Cast a ray from the camera through the mouse position.
                var from = GetNode<Camera3D>("/root/Main/Camera3D").ProjectRayOrigin(mousePosition);
                GD.Print("from" + from);
                var to = GetNode<Camera3D>("/root/Main/Camera3D").ProjectRayNormal(mousePosition) * 100; // Adjust the distance as needed.
                GD.Print("to" + to);

                // Perform the raycast.
				// Position = from;
                Position = from;
                TargetPosition = to;
                ForceRaycastUpdate(); // Update the raycast immediately.

                // Check if the ray hit an object.
                if (IsColliding())
                {
                    var hitPosition = GetCollisionPoint();
                    var hitObject = GetCollider();

                    // You can now access the hit object and its position.
                    GD.Print("Hit: " + GetCollider().GetClass());
                }
            }
        }
    }

	// Called every frame. 'delta' is the elapsed time since the previous frame.
	public override void _Process(double delta)
	{
	}
}
