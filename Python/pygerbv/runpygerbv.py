from pygerber.gerberx3.api import (
      ColorScheme,
      Rasterized2DLayer,
      Rasterized2DLayerParams,
)

# Path to Gerber source file.
source_path = "test_file.gbt"

Rasterized2DLayer(
      options=Rasterized2DLayerParams(
            source_path=source_path,
            colors=ColorScheme.COPPER_ALPHA,
      ),
).render().save("output.png")
