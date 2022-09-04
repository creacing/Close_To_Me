<template>
  <div class="inner">
    <div id="main" class="pjax">
      <slot name="content"></slot>
    </div>
    <Sidebar />
    <div class="dimmer"></div>
  </div>
</template>
  <script setup>
import Pagination from "@/components/Pagination.vue";
import Sidebar from "@/components/Sidebar.vue";
</script>
  
  
  