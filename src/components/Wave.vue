<template>
  <svg
    class="waves pos-rel"
    xmlns="http://www.w3.org/2000/svg"
    xmlns:xlink="http://www.w3.org/1999/xlink"
    viewBox="0 24 150 28"
    preserveAspectRatio="none"
    shape-rendering="auto"
  >
    <defs>
      <path
        id="gentle-wave"
        d="M-160 44c30 0 58-18 88-18s 58 18 88 18 58-18 88-18 58 18 88 18 v44h-352z"
      />
    </defs>
    <g class="parallax">
      <use xlink:href="#gentle-wave" x="48" y="0" />
      <use xlink:href="#gentle-wave" x="48" y="3" />
      <use xlink:href="#gentle-wave" x="48" y="5" />
      <use xlink:href="#gentle-wave" x="48" y="7" />
    </g>
  </svg>
</template>
<script>
</script>
<style lang="scss" scoped>
.waves {
  width: 100%;
  height: 15vh;
  margin-bottom: -0.6875rem;
  min-height: 3.125rem;
  max-height: 9.375rem;
  z-index: 998;
  .parallax {
    use {
      animation: wave 25s cubic-bezier(0.55, 0.5, 0.45, 0.5) infinite;
    }
    use:nth-child(1) {
      animation-delay: -2s;
      animation-duration: 7s;
      fill: var(--grey-1-a7);
    }
    use:nth-child(2) {
      animation-delay: -3s;
      animation-duration: 10s;
      fill: var(--grey-1-a5);
    }
    use:nth-child(3) {
      animation-delay: -4s;
      animation-duration: 13s;
      fill: var(--grey-1-a3);
    }
    use:nth-child(4) {
      animation-delay: -5s;
      animation-duration: 20s;
      fill: var(--grey-1);
    }
  }
}

@media (max-width: 767px) {
  .waves {
    height: 10vh;
  }
}
</style>