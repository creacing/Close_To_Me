<template>
  <div class="footer">
    <Copyright />
  </div>
</template>
<script setup>
import Copyright from "@/components/Copyright.vue";
</script>
<style lang="scss" scoped>
.footer {
  margin: 0 auto;
}

@media (min-width: 1200px) {
  .footer {
    width: 72.5rem;
  }
}
</style>