<template>
  <div class="layout flex-row">
    <div id="main" class="slide-up-big-in main pos-rel">
      <slot name="content" />
    </div>
  </div>
</template>
<script setup>
</script>
<style scoped lang='scss'>
.layout {
  margin: 0 auto;
  justify-content: center;
  align-items: flex-start;
  .main {
    padding: 1.25rem;
    background: linear-gradient(to top, var(--grey-0) 0, var(--grey-1) 20%)
      no-repeat top;
    box-shadow: 0 1.25rem 1rem 0.3125rem var(--body-bg-shadow);
    width: calc(100% - 15.75rem);
    min-height: 100vh;
    flex: auto;
  }
}

@media (min-width: 1200px) {
  .layout {
    width: 65rem;
  }
}

#main .wrap {
  position: relative;
  padding: 1.25rem;
}

#main .wrap:nth-child(1) {
  margin-bottom: 1.25rem;
}

@media (max-width: 991px) {
  #main {
    width: 100%;
  }

  #main .wrap {
    padding: 0.625rem;
  }
}

@media (max-width: 767px) {
  #main .wrap {
    padding: 0.5rem;
  }
}
</style>